/*
 * Challenger 1P Hello World Program for cc65.
 */

#include <conio.h>

int main(void)
{
    static const char hello_world[] =
            "Hello world!\r\ncc65 for Challenger 1P";

    unsigned int i;

    clrscr();

    gotoxy(0, 0);

    cputs(hello_world);

    gotoxy(0, 4);

    for (i = 0; i < 256; i += 1) {
        if (i != '\n' && i != '\r') {
            cputc((unsigned char ) i);
        }
    }

    cputsxy(0, 14, "cputsxy\r\n");

    cprintf("cprintf '%s' %d %d\r\n", "string", (int) wherex(), (int) wherey());
    cputs("now type something:\r\n");

    while (1) {
        char c = cgetc();
        cputc(c);
    }

    return 0;
}
