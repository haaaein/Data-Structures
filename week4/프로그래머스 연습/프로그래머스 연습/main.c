#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(char* word)
{
    int answer = 0;
    answer = atoi(word);
    return answer;
}

int main(void)
{
    char word[20];
    int answer;
    scanf("%s", word);
    answer = solution(word);
    printf("%d\n", answer);
}
