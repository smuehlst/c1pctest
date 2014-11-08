CC65BINDIR = ../../cc65/bin
CL   = $(CC65BINDIR)/cl65
CC   = $(CC65BINDIR)/cc65
AS   = $(CC65BINDIR)/ca65
LD   = $(CC65BINDIR)/ld65
C1P65 = $(CC65BINDIR)/c1p65

hello.c1p: hello.c ../../cc65/lib/c1p.lib
	$(CL) -t c1p hello.c
	$(C1P65) hello
