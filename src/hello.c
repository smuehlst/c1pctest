#define VIDEO_RAM_START ((char *) 0xd000)

extern void clrscr(void);

int
main()
{
#if 0
    int scrpos = 0x224;

    static const char hello_world[] = "Hello world!";
    const char *cp;

#endif

    clrscr();

    *(VIDEO_RAM_START + 0x224) = 'A';

#if 0
    for (cp = hello_world, scrpos = 0x224; *cp; scrpos +=1, cp += 1)
    {
	*(VIDEO_RAM_START + scrpos) = *cp;
    }
#endif

    while (1);
	
    return 0;
}

