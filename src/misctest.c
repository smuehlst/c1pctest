/*
 * misctest.c
 *
 * miscellaneous tests
 */

#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include <ctype.h>

typedef void (*fp)(void);

typedef struct
{
    const char *test_name;
    fp test_fp;
} test;

static
void t_malloc(void)
{
    char *p = (char *) malloc(10);

    if (p) {
        cprintf("malloc succeeded, pointer is %p\r\n", p);
        p = (char *) realloc(p, 20);
        if (p) {
            cprintf("realloc succeeded, pointer is %p\r\n", p);
        } else {
            cputs("realloc failed\r\n");
        }
        free(p);
    } else {
        cputs("malloc failed");
    }

    free(0);
    cputs("free(0) succeeded\r\n");
}

static
void do_longjmp(jmp_buf *env)
{
    cputs("Before longjmp\r\n");
    longjmp(*env, 42);
}

static
void t_longjmp(void)
{
    jmp_buf env;
    int jmpval = setjmp(env);

    if (jmpval != 0) {
        cprintf("After longjmp, got %d\r\n", jmpval);
    } else {
        do_longjmp(&env);
    }
}

unsigned int fib(unsigned int n)
{
    int result;

    if (n == 0)
        result = 0;
    else if (n == 1)
        result = 1;
    else
        result = fib(n - 1) + fib(n - 2);

    return result;
}

static
void t_recursion(void)
{
    int i;

    cputs("Fibonacci test\r\n\r\n");
    for (i = 0; i < 10; i += 1) {
        cprintf("fib(%d) == %d\r\n", i, fib(i));
    }
}

static
void t_conio(void)
{
    unsigned char xsize, ysize;
    unsigned char i;

    screensize(&xsize, &ysize);

    cprintf("Screen size is %ux%u\r\n",
            (unsigned int) xsize, (unsigned int) ysize);
    cputs("Line created with chline(), partially blanked out with "
            "cclear():\r\n");
    chline(10);
    cclearxy(2, wherey(), 6);
    gotoxy(0, wherey() + 1);
    for (i = 0; i < xsize; i += 1) {
        cputc('0' + (i % 10));
    }

    {
        int n, decimalnum;
        char name[50];

        cursor(1);
        cputs("\r\nEnter decimal number and string\r\n");
        n = cscanf("%d %s", &decimalnum, name);
        cprintf("\r\ngot %d and '%s'\r\n", decimalnum, name);
    }
}

static
void t_ctype(void)
{
    static char const s[] = "!\"abc123ABC?=";
    const char *p;

    cputs("original string:");
    for (p = s; *p; p += 1)
    {
        cputc(*p);
    }
    cputs("\r\n");

    cputs("toupper:");
    for (p = s; *p; p += 1)
    {
        cputc(toupper(*p));
    }
    cputs("\r\n");

    cputs("tolower:");
    for (p = s; *p; p += 1)
    {
        cputc(tolower(*p));
    }
    cputs("\r\n");
}

static
void t_kbhit(void)
{
    unsigned char const column = 3;
    unsigned char const line = 5;
    unsigned char const limit = 10;
    unsigned char n = 0;

    cputs("kbhit() test, press some keys\r\n");
    cputs("'q' to quit test\r\n");

    while (1)
    {
        cputcxy(column, line + n, ' ');
        n = (n + 1) % limit;
        cputcxy(column, line + n, '*');
        if (kbhit())
        {
            char const c = cgetc();
            cputcxy(column + 1, line + n, c);
            if (c == 'q' || c == 'Q')
            {
                break;
            }
        }
    }
}

static test const tests[] =
{
    { "malloc", t_malloc },
    { "longjmp/setjmp", t_longjmp },
    { "recursion", t_recursion },
    { "conio", t_conio },
    { "ctype", t_ctype },
    { "kbhit", t_kbhit }
};

int main(void)
{
    unsigned char i, count;

    for (i = 0, count = sizeof(tests) / sizeof(tests[0]); i < count; i += 1) {
        clrscr();
        cprintf("Test %d of %d: %s\r\n\r\n", (int) i + 1, (int) count,
                    tests[i].test_name);
        tests[i].test_fp();
        cputs("Press <RETURN>\r\n");
        cgetc();
    }

    clrscr();
    gotoxy(0, 10);
    cputs("Tests finished\r\nPress <RETURN>\r\n");

    cgetc();

    return 0;
}
