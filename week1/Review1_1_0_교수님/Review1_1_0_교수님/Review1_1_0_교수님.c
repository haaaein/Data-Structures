#include <stdio.h>
#include <string.h>
void print_reverse(char *str, int end)
{
    char tmp;
    
    printf("%c", str[end]);
    if (end == 0)
        return;
    else
        //여기에 코드 추가
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
