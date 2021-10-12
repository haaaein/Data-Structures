#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef char* string;

typedef struct StackNode {
    element data;
    string strNum;
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

void push(LinkedStackType *s, element data, string str)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "메모리 할당 에러\n");
        return;
    }
    else {
        temp->data = data;
        temp->strNum = str;
        temp->link = s->top;
        s->top = temp;
    }
}

void stack_print(LinkedStackType *s)
{
    if (is_empty(s))
        printf("<empty>\n");
    
    for (StackNode *p = s->top; p != NULL; p = p->link) {
        printf("[%d, %s] ", p->data, p->strNum);
        if (p == s->top)
            printf(" <- top");
        printf("\n");
    }
    printf("--\n");
}

void pop(LinkedStackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode *temp = s->top;
        element data = temp->data;
        string str = temp->strNum;
        s->top = s->top->link;
        free(temp);
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
    push(&s, 10, "ten");
    stack_print(&s);
    push(&s, 20, "twenty");
    stack_print(&s);
    push(&s, 30, "thirty");
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
    pop(&s);
    stack_print(&s);
}

