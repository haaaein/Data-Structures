#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef int element;

typedef struct {
    element data[MAX_STACK_SIZE];
    char word[MAX_STRING];
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full (StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top) --];
}

element peek(StackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[s->top];
}

int palindrome(char str[])
{
    StackType s;
  
    int i;
    init(&s);
    
    for (i = 0; str[i] != 0; i++)
        push(&s, str[i]);
    
    for (i = 0; str[i] != 0; i++) {
        if (str[i] != pop(&s))
            return 0;
    }
    
    return 1;
}
int main()
{
    char word[MAX_STRING];
    
    printf("Enter a word to check palindrome: ");
    scanf("%s", word);
    
    if (palindrome(word))
        printf("palindrome 입니다.\n");
    else
        printf("palindrome이 아닙니다. \n");
}
