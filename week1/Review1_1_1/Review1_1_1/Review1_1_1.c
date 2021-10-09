#include <stdio.h>
#include <string.h>
void reverse_string(char *str, int s, int e)
{
    char tmp;
    
    if (s > e)
        return;
    
    else {
        reverse_string(str, s + 1, e - 1);
        tmp = str[e];
        str[e] = str[s];
        str[s] = tmp;
    }
}

int main()
{
    char str[100];

    printf("Enter any string: ");
    scanf("%s", str);

    reverse_string(str, 0, strlen(str) - 1);
    printf("\nReversed String is: %s\n", str);
    return 0;
}
