#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
    DListNode* p;
    
    if (phead->llink == phead)
        printf("NULL\n");
    
    else {
        for (p = phead->rlink; p != phead; p = p->rlink) {
            printf("<- |%d| |->", p->data);
        }
        printf("\n");
    }
}

void dinsert(DListNode *before, element data)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if (removed == head) return;
    
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    
    free(removed);
}

void print_reverse_dlist(DListNode* phead)
{
    DListNode* p;
    
    for (p = phead->llink; p != phead; p = p->llink)
        printf("<- |%d| |->", p->data);
 
    printf("\n");
}

DListNode* search(DListNode *head, element data)
{
    DListNode* p;
    
    for (p = head->rlink; p != head; p = p->rlink) {
        if (p->data == data) {
            printf("찾으려는 data는 %d 입니다.\n", p->data);
            return p;
        }
    }
    
    printf("찾으려는 data가 없습니다.\n");
    return NULL;
}

int main(void)
{
    DListNode* head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    printf("추가 단계\n");
    
    dinsert(head, 10);
    print_dlist(head);
    dinsert(head, 20);
    print_dlist(head);
    dinsert(head, 30);
    print_dlist(head);
    
    //맨 뒤에 노드를 삽입하려면?
    dinsert(head->llink, 90);
    print_dlist(head);
    
    printf("\n역순으로 출력\n");
    print_reverse_dlist(head);
    
    search(head, 90);
    
    printf("\n삭제 단계\n");
    //맨 앞의 노드를 삭제
    ddelete(head, head->rlink);
    print_dlist(head);
    
    //맨 뒤의 노드를 삭제하려면?
    ddelete(head, head->llink);
    print_dlist(head);
    
    ddelete(head, head->llink);
    print_dlist(head);
    
    ddelete(head, head->llink);
    print_dlist(head);
    
    free(head);
    return 0;
}
