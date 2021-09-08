#include <stdio.h>

int fact(int n)
{
    if (n <= 1)
        return 1;

    return n * fact(n - 1);
}

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%d! = ", n);
    printf("%d\n", fact(n));
}