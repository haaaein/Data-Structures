#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING_SIZE 100

typedef int element;

typedef struct {
    element data[MAX_STRING_SIZE];
    char* strNum[MAX_STRING_SIZE];
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

void push(StackType *s, element item, char* item2)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
        s->strNum[s->top] = item2;
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
        printf("[%d, %s] ", s->data[i], s->strNum[i]);
        
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
    
    init(&s);
    stack_print(&s);
    push(&s, 10, "ten");
    stack_print(&s);
    push(&s, 20, "twenty");
    stack_print(&s);
    push(&s, 30, "thrity");
    stack_print(&s);
    push(&s, 40, "forty");
    stack_print(&s);
    
    pop(&s);
    stack_print(&s);
    push(&s, 50, "fifty");
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
}
