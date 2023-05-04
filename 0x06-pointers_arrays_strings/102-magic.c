#include <stdio.h>

int main(void)
{
    int n;
    int a[5];
    int *p;

    a[2] = 1024;
    p = &n;

    *(p + 3) = 98; /* Assign the value 98 to the memory location pointed to by p */

    printf("a[2] = %d\n", a[2]); /* This should print "a[2] = 98" */

    return 0;
}
