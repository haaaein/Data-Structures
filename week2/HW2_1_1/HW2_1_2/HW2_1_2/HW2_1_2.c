#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING_SIZE 100

typedef struct {
    char str[MAX_STRING_SIZE];
    int num;
} element;

typedef struct {
    element data[MAX_STACK_SIZE];
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
    else {
        s->data[++(s->top)] = item;
    }
    
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

void stack_print(StackType *s)
{
    int i = 0;
    
    if (is_empty(s))
        printf("<empty>\n");
    
    for (i = s->top; i >= 0; i--) {
        printf("[%d, %s] ", s->data[i].num, s->data[i].str);
        
        if (i == s->top)
            printf("<- top\n");
        else
            printf("\n");
    }
    
    printf("--\n");
    
}

int main()
{
    StackType s;
    element item;
    
    init(&s);
    stack_print(&s);
    item.num = 10;
    strcpy(item.str, "ten");
    push(&s, item);
    stack_print(&s);
    
    item.num = 20;
    strcpy(item.str, "twenty");
    push(&s, item);
    stack_print(&s);
    
    item.num = 30;
    strcpy(item.str, "thirty");
    push(&s, item);
    stack_print(&s);
    
    item.num = 40;
    strcpy(item.str, "forty");
    push(&s, item);
    stack_print(&s);
    
    pop(&s);
    stack_print(&s);
    item.num = 50;
    strcpy(item.str, "fifty");
    push(&s, item);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
}
