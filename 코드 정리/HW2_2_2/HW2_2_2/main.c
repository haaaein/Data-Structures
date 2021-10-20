#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 100

typedef struct {
    char str[MAX_STRING_SIZE];
    int num;
} element;

typedef struct StackNode {
    element item;
    struct StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
    s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
    return s->top == NULL;
}

int is_full(LinkedStackType *s)
{
    return 0;
}

void push(LinkedStackType *s, element data)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    
    if (temp == NULL) {
        fprintf(stderr, "메모리 할당 에러\n");
        return;
    }
    else {
        temp->item = data;
        temp->link = s->top;
        s->top = temp;
    }
}

void stack_print(LinkedStackType *s)
{
    if (is_empty(s))
        printf("<empty>\n");
    
    for (StackNode *p = s->top; p != NULL; p = p->link) {
        printf("[%d, %s] ", p->item.num, p->item.str);
        if (p == s->top)
            printf(" <- top");
        printf("\n");
    }
    printf("--\n");
}

element pop(LinkedStackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode *temp = s->top;
        element item = temp->item;
        s->top = s->top->link;
        free(temp);
        return item;
    }
}

element peek(LinkedStackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        return s->top->item;
    }
}

int main(void)
{
    LinkedStackType s;
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

