#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

typedef TreeNode* element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s)
{
    s->top = NULL;
}

int is_empty(LinkedStackType* s)
{
    return (s->top == NULL);
}

int is_full(LinkedStackType* s)
{
    return 0;
}

void push(LinkedStackType* s, element item)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

element pop(LinkedStackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Ω∫≈√¿Ã ∫ÒæÓ¿÷¿Ω\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        element data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

TreeNode* insert_node(TreeNode* root, int data)
{
    TreeNode* p, * t;
    TreeNode* n;

    t = root;
    p = NULL;

    
    while (t != NULL) {
        //if( data == t->data ) return root;
        p = t;
            
        if (data < t->data)
            t = t->left;
        else
            t = t->right;
    }
    
    n = (TreeNode*)malloc(sizeof(TreeNode));
   
    n->data = data;
    n->left = n->right = NULL;

    
    if (p != NULL)
        if (data < p->data)
            p->left = n;
        else
            p->right = n;
    else
        root = n;
    return root;
}

void preorder_iter(LinkedStackType* s, TreeNode* root)
{
    while (1) {
        for (; root; root = root->left) {
            printf("[%d] ", root->data);
            push(s, root);
            
        }
        if (is_empty(s))
            break;
        else
            root = pop(s);
        root = root->right;
    }
    return;
}

int main(void)
{
    LinkedStackType s;
    TreeNode* root;
    int n;

    // (B)
    //          15
    //       4         20
    //    1          16  25
    TreeNode n1 = { 1,  NULL, NULL };
    TreeNode n2 = { 4,  &n1,  NULL };
    TreeNode n3 = { 16, NULL, NULL };
    TreeNode n4 = { 25, NULL, NULL };
    TreeNode n5 = { 20, &n3,  &n4 };
    TreeNode n6 = { 15, &n2,  &n5 };
    root = &n6;

    //
    /*(A)
    root = NULL;
    scanf("%d", &n);
    while (n != -1) {
        root = insert_node(root, n);
        scanf("%d", &n);
    }
    */

    init(&s);
    preorder_iter(&s, root);
    printf("\n");
    return 0;
}
