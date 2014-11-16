/*
 * Challenger 1P cc65 minimal test program.
 *
 * This program does not use any library function. It only displays a
 * single 'A' character on the screen.
 */
#define VIDEO_RAM_START ((char *) 0xd000)

int
main()
{
    *(VIDEO_RAM_START + 0x224) = 'A';

    while (1);
	
    return 0;
}
