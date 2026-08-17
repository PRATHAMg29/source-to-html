#include <stdio.h>
#define MAX 100

// single line comment
/* multi
   line comment */

int source(void)
{
    int a = 10;
    float b = 3.14;
    char ch = '\n';
    char *str = "Hello <HTML> & C";

    if (a < 20 && b > 1.0)
    {
        printf("%d %f %c %s\n", a, b, ch, str);
    }

    return 0;
}