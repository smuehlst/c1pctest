#
# Makefile for building programs with cc65 for the osic1p target
#
# From a source file <file>.c the following output can be produced:
#
# <file>		Plain machine code executable
# <file>.c1p	Executable formatted for uploading over 65 PROM monitor
# <file>.wav	Executable as WAV file for upload over cassette port
#
# For producing the .c1p files the srec_cat program from the
# SRecord tool collection (http://srecord.sourceforge.net/) is needed.
#
# For producing the WAV files the kcs_encode.py Python program
# by David Beazley (http://www.dabeaz.com) is used. It requires
# Python 3.1.2 or newer.

ifneq ($(shell echo),)
  CMD_EXE = 1
endif

ifdef CMD_EXE
RM := del /f
else
RM := rm -f
endif

CC65DIR = ../../cc65
CC65BINDIR = $(CC65DIR)/bin
CC65LIBDIR = $(CC65DIR)/lib
CL   = $(CC65BINDIR)/cl65
CC   = $(CC65BINDIR)/cc65
AS   = $(CC65BINDIR)/ca65
LD   = $(CC65BINDIR)/ld65
SREC_CAT = srec_cat
PYTHON3 = python

CFLAGS = -O

STARTADDR = 0x200

.SUFFIXES: .c1p .wav

PROGS = hello hello8k minimal misctest asmonly Eliza
OSIC1PTARGETS = $(PROGS:=.c1p)
WAVTARGETS = $(OSIC1PTARGETS:.c1p=.wav)

all: $(OSIC1PTARGETS)

wavs: $(WAVTARGETS)

$(OSIC1PTARGETS): $(CC65LIBDIR)/osic1p.lib

# Link program for 8 kB RAM by defining __HIMEM__ symbol
hello8k.c1p: hello.c
	$(CL) $(CFLAGS) --start-addr $(STARTADDR) -Wl -D,__HIMEM__=$$2000 --mapfile hello8k.map -vm -t osic1p -o hello8k $<
	$(SREC_CAT) hello8k -binary -offset $(STARTADDR) -o hello8k.c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

# Generate loadable program from C source
.c.c1p:
	$(CL) $(CFLAGS) --start-addr $(STARTADDR) --mapfile $(basename $<).map -vm -t osic1p $<
	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o $(basename $<).c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

# Generate loadable program from assembler source
.s.c1p:
	$(CL) $(ASFLAGS) -C osic1p-asm.cfg --start-addr $(STARTADDR) --mapfile $(basename $<).map -vm -t osic1p $<
	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o $(basename $<).c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

# Generate Kansas City Standard WAV file for upload over cassette port
.c1p.wav:
	$(PYTHON3) kcs_encode.py $< $(basename $<).wav
	
clean:
	$(RM) $(OSIC1PTARGETS) $(WAVTARGETS)
