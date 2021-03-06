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
# For producing the WAV files a modified version of the  kcs_encode.py Python
# program by David Beazley (http://www.dabeaz.com) is used. It requires
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
CC65LIB = $(CC65LIBDIR)/osic1p.lib
CL   = $(CC65BINDIR)/cl65
CC   = $(CC65BINDIR)/cc65
AS   = $(CC65BINDIR)/ca65
LD   = $(CC65BINDIR)/ld65
SREC_CAT = srec_cat
PYTHON3 = python

CFLAGS = -O

STARTADDR = 0x200

# RAM size by default 32 kB
HIMEM = 0x8000

.SUFFIXES: .c1p .wav

PROGS = hello minimal misctest asmonly Eliza
OSIC1PTARGETS = $(PROGS:=.c1p)
WAVTARGETS = $(OSIC1PTARGETS:.c1p=.wav)

all: $(OSIC1PTARGETS)

wavs: $(WAVTARGETS)

$(OSIC1PTARGETS): $(CC65LIB)

# Link program for Superboard /// in 32x28 screen mode
hellos3-32x28.c1p: hello.c $(CC65LIB)
	$(CL) $(CFLAGS) --start-addr $(STARTADDR) -Wl -D,__HIMEM__=$(HIMEM) --mapfile hellos3-32x28.map -vm -t osic1p -o hellos3-32x28 osic1p-screen-s3-32x28.o $<
	$(SREC_CAT) hellos3-32x28 -binary -offset $(STARTADDR) -o hellos3-32x28.c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

# Generate loadable program from C source in hybrid format
.c.c1p:
	$(CL) $(CFLAGS) -u __BOOT__ --start-addr $(STARTADDR) -Wl -D,__HIMEM__=$(HIMEM) --mapfile $(basename $<).map -vm -t osic1p -o $(basename $<).c1p $<

# Generate loadable program from C source
# This is no longer recommended as the upload takes much longer
#.c.c1p:
#	$(CL) $(CFLAGS) --start-addr $(STARTADDR) -Wl -D,__HIMEM__=$(HIMEM) --mapfile $(basename $<).map -vm -t osic1p $<
#	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o $(basename $<).c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

# Generate loadable program from assembler source
.s.c1p:
	$(CL) $(ASFLAGS) -C osic1p-asm.cfg --start-addr $(STARTADDR) -Wl -D,__HIMEM__=$(HIMEM) --mapfile $(basename $<).map -vm -t osic1p $<
	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o $(basename $<).c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

# Generate Kansas City Standard WAV file for upload over cassette port
.c1p.wav:
	$(PYTHON3) kcs_encode_bin.py $< $(basename $<).wav
	
clean:
	$(RM) $(OSIC1PTARGETS) $(WAVTARGETS)
