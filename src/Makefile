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

CFLAGS = -O

STARTADDR = 0x200

.SUFFIXES: .c1p

C1PTARGETS = hello.c1p hello8k.c1p minimal.c1p misctest.c1p asmonly.c1p Eliza.c1p

all: $(C1PTARGETS)

# Link program for 8 kB RAM by defining __HIMEM__ symbol
hello8k.c1p: hello.c
	$(CL) $(CFLAGS) --start-addr $(STARTADDR) -Wl -D,__HIMEM__=$$2000 --mapfile hello8k.map -vm -t c1p $<
	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o hello8k.c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

$(C1PTARGETS): $(CC65LIBDIR)/c1p.lib

.c.c1p:
	$(CL) $(CFLAGS) --start-addr $(STARTADDR) --mapfile $(basename $<).map -vm -t c1p $<
	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o $(basename $<).c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

.s.c1p:
	$(CL) $(ASFLAGS) -C c1p-asm.cfg --start-addr $(STARTADDR) --mapfile $(basename $<).map -vm -t c1p $<
	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o $(basename $<).c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)

clean:
	$(RM) $(C1PTARGETS)