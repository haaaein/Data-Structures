#include <stdio.h>
#include <string.h>
void reverse_string(char *str, int s, int e)
{
    char tmp;
    if (s >= e)
        return;
    
    //str[s]와 str[e]를 바꾸고
    //재귀를 부른다
}

int main()
{
    char str[100];

    printf("Enter any string: ");
    scanf("%s", str);

    reverse_string(str, 0, strlen(str) - 1);
    printf("\nReversed String is: %s", str);
    return 0;
}
