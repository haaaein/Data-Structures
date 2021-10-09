#include <stdio.h>
#include <string.h>

void reverse_string(char *str, int s, int e)
{
    char tmp;
    int i;
    int half = e / 2;
    
    for (i = e; i >= half; i--) {
        tmp = str[i];
        str[i] = str[s];
        str[s++] = tmp;
    }
}
int main()
{
    char str[100];
    printf("Enter any string:");
    scanf("%s", str);
    reverse_string(str, 0, strlen(str) - 1);
    printf("\nReversed String is: %s\n", str);
    return 0;
}

