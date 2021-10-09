#include <stdio.h>
#include <string.h>
void reverse_string(char *str, int s, int e)
{
    char tmp;
    while (s < e) {
        //str[s]와 str[e]를 바꾸고
        //s를 증가시키고 e는 감소
    }
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
