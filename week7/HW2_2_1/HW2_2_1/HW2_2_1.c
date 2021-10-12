#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element data;
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
        temp->data = data;
        temp->link = s->top;
        s->top = temp;
    }
}

void stack_print(LinkedStackType *s)
{
    if (is_empty(s))
        printf("<empty>\n");
    
    for (StackNode *p = s->top; p != NULL; p = p->link) {
        printf("%d", p->data);
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
        element data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

element peek(LinkedStackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        return s->top->data;
    }
}

int main(void)
{
    LinkedStackType s;
    
    init(&s);
    stack_print(&s);
    push(&s, 10);
    stack_print(&s);
    push(&s, 20);
    stack_print(&s);
    push(&s, 30);
    stack_print(&s);
    push(&s, 40);
    stack_print(&s);
    
    pop(&s);
    stack_print(&s);
    push(&s, 50);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
    pop(&s);
    stack_print(&s);
}

