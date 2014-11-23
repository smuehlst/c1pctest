CC65BINDIR = ../../cc65/bin
CC65LIBDIR = ../../cc65/lib
CL   = $(CC65BINDIR)/cl65
CC   = $(CC65BINDIR)/cc65
AS   = $(CC65BINDIR)/ca65
LD   = $(CC65BINDIR)/ld65
C1P65 = $(CC65BINDIR)/c1p65

STARTADDR = 0x300

.SUFFIXES: .c1p

C1PTARGETS = hello.c1p minimal.c1p

all: $(C1PTARGETS)

$(C1PTARGETS): $(CC65LIBDIR)/c1p.lib

.c.c1p:
	$(CL) --start-addr $(STARTADDR) --mapfile $(basename $<).map -vm -t c1p $<
	$(C1P65) -S $(STARTADDR) $(basename $<)
