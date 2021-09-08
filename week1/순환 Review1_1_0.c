#include <stdio.h>
#include <string.h>
void print_reverse(char *str, int end)
{
    if (*str == '\0')
        return;

    else
    {
        print_reverse(str + 1, end);
        printf("%c", *str);
    }
}

int main()
{
    char str[100];

    printf("Enter any string: ");
    scanf("%s", str);

    printf("Reversed String is: ");
    print_reverse(str, strlen(str) - 1);
    return 0;
}
