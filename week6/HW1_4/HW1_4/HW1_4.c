#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode* head)
{
    ListNode *p;
    
    if(head == NULL) return;
    p = head->link;
    
    while (p != head) {
        printf("%d->", p->data);
        p = p->link;
    }
    
    printf("%d->", p->data); //마지막 노드 출력
    printf("리스트의 끝\n");
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    
    node->data = data;
    if (head == NULL) {
        head = node;
        head->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode *head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    
    node->data = data;
    if (head == NULL) {
        head = node;
        head->link = head;
    }
    node->link = head->link;
    head->link = node;
    head = node;
    
    return head;
}


ListNode* delete_first(ListNode* head)
{
    ListNode *temp;
    
    if (head == NULL) {
        printf("리스트가 비어 삭제를 못함\n");
        return NULL;
    }
    
    if (head == head->link) {//노드가 1개
        free(head);
        head = NULL;
    }
    
    else {//노드가 2개 이상
        temp = head->link;
        head->link = temp->link;
        free(temp);
    }
    
    return head;
}

ListNode* delete_last(ListNode* head)
{
    ListNode *temp = head->link;
    ListNode *prevTemp = NULL;
    
    if (head == NULL) {
        printf("리스트가 비어 삭제를 못함\n");
        return NULL;
    }

    if (head == head->link) {//노드가 1개
        free(head);
        head = NULL;
    }
    
    else {
        while (temp != head) {
            prevTemp = temp;
            temp = temp->link;
        }
    
        prevTemp->link = temp->link;
        head = prevTemp;
        free(temp);
    }
    
    return head;
}

ListNode* search(ListNode *head, element data)
{
    ListNode *p;
    
    if(head == NULL) {
        printf("NULL\n");
        return NULL;
    }
    
    p = head->link;
    
    while (p != head) {
        if (p->data == data) {
            printf("%d는 리스트에 있습니다.\n", p->data);
            return p;
            break;
        }
        p = p->link;
    }
    printf("%d는 리스트에 없습니다.\n", data);
    return head;
}

int get_size(ListNode* head)
{
    int first;
    int size = 0;
    
    if (head == NULL)
        size = 0;
    
    else {
        first = head->data;
        do {
            size++;
            head = head->link;
        } while (head->data != first);
    }
    
    return size;
}

int main(void)
{
    ListNode *head = NULL;
    ListNode *test = NULL;
    
    //list=10->20->30->40
    head = insert_last(head, 20);
    print_list(head);
    
    head = insert_last(head, 30);
    print_list(head);
    head = insert_last(head, 40);
    print_list(head);
    head = insert_first(head, 10);
    print_list(head);
    
    head = delete_first(head);
    print_list(head);
    head = delete_last(head);
    print_list(head);
    printf("길이는 %d\n", get_size(head));
    head = delete_last(head);
    print_list(head);
    printf("길이는 %d\n", get_size(head));
    head = delete_last(head);
    print_list(head);
    printf("길이는 %d\n", get_size(head)); //노드 없을때도 ok
    
    printf("--test--\n");
    test = insert_last(test, 100);
    print_list(test);
    
    head = insert_last(test, 300);
    print_list(test);
    head = insert_last(test, 500);
    print_list(test);
    head = insert_first(test, 700);
    print_list(test);
    search(test, 700); //리스트에 있음
    search(test, 900); //리트스에 없음
    test = delete_last(test);
    test = delete_last(test);
    test = delete_last(test);
    test = delete_last(test);
    search(test, 700); //NULL일때
    return 0;
}
