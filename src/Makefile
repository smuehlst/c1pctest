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

C1PTARGETS = hello.c1p minimal.c1p misctest.c1p

all: $(C1PTARGETS)

$(C1PTARGETS): $(CC65LIBDIR)/c1p.lib

.c.c1p:
	$(CL) $(CFLAGS) --start-addr $(STARTADDR) --mapfile $(basename $<).map -vm -t c1p $<
	$(SREC_CAT) $(basename $<) -binary -offset $(STARTADDR) -o $(basename $<).c1p -Ohio_Scientific -execution-start-address=$(STARTADDR)
