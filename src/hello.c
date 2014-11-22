/*
 * Challenger 1P Hello World Program for cc65.
 */

#include <conio.h>

#define VIDEO_RAM_START ((char *) 0xd000)

int main()
{
    static const char hello_world[] = "Hello world!";

    const char *cp;
    unsigned int i;

    clrscr();

    gotoxy(0, 0);

    cputs(hello_world);

    gotoxy(2, 0);

    for (i = 0; i < 256; i += 1) {
        cputc((unsigned char ) i);
    }

    while (1)
    {
        char c = cgetc();
        cputc(c);
    }

    return 0;
}
