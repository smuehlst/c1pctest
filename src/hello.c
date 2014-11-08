/*
 * Challenger 1P Hello World Program for cc65.
 */

#include <conio.h>

#define VIDEO_RAM_START ((char *) 0xd000)

int main()
{
    static const char hello_world[] = "Hello world!";

    int scrpos;
    const char *cp;

    clrscr();

    for (cp = hello_world, scrpos = 0x083; *cp; scrpos += 1, cp += 1)
    {
        *(VIDEO_RAM_START + scrpos) = *cp;
    }

    while (1)
    {
        char c = cgetc();
        *(VIDEO_RAM_START + scrpos++) = c;
    }

    return 0;
}
