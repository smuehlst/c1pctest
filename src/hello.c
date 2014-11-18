/*
 * Challenger 1P Hello World Program for cc65.
 */

#include <conio.h>

#define VIDEO_RAM_START ((char *) 0xd000)

int main()
{
    static const char hello_world[] = "Hello world!\n";

    const char *cp;
    unsigned int i;

    clrscr();

    for (cp = hello_world; *cp; cp += 1)
    {
        cputc(*cp);
    }

    for (i = 0; i < 256; i += 1) {
        cputc((unsigned char ) i);
    }

    cputc(' ');
    cputc((char) wherex());

    while (1)
    {
        char c = cgetc();
        cputc(c);
    }

    return 0;
}
