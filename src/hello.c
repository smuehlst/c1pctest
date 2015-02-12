/*
 * Challenger 1P Hello World Program for cc65.
 */

#include <conio.h>

int main(void)
{
    static const char hello_world[] =
            "Hello world!\r\ncc65 for Challenger 1P";

    unsigned int i;
	char xwidth, ywidth;

    clrscr();

    cputs(hello_world);

    /* kbhit() is currently a dummy function that returns always true */
    if (kbhit()) {
        gotoxy(0, 4);
    }

    /* Output a few graphical symbols */
    for (i = 0; i < 0x20; i += 1) {
        if (i != '\n' && i != '\r') {
            cputc((unsigned char ) i);
        }
    }

    cputsxy(0, 7, "cputsxy\r\n");

    cprintf("cprintf '%s' %d %d\r\n", "string", (int) wherex(), (int) wherey());
    screensize(&xwidth, &ywidth);
    chline(ywidth);
    gotox(0);
    cvline(2);
    cvlinexy(xwidth - 1, wherey() - 2, 2);
    chlinexy(0, wherey(), xwidth);
    cprintf("width %d height %d\r\n", (int) xwidth, (int) ywidth);
    cputs("now type (vi keys for positioning, "
            "'A' cursor on, 'B' cursor off):\r\n");

    /* cursor on */
    cursor(1);

    while (1) {
        unsigned char const xpos = wherex();
        unsigned char const ypos = wherey();

        char const c = cgetc();

        /* Test cursor on/off and cursor positioning */
        switch (c) {
            case 'A':
                cursor(1);
                break;
            case 'B':
                cursor(0);
                break;
            case 'H':
                if (xpos > 0) {
                    gotox(xpos - 1);
                }
                break;
            case 'L':
                if (xpos < 24) {
                    gotox(xpos + 1);
                }
                break;
            case 'K':
                if (ypos > 0) {
                    gotoy(ypos - 1);
                }
                break;
            case 'J':
                if (ypos < 24) {
                    gotoy(ypos + 1);
                }
                break;
            default:
                cputc(c);
                break;
        }
    }

    return 0;
}
