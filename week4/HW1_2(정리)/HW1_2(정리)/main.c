#include <stdio.h>
#include <stdlib.h>

typedef int  element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//노드 pre뒤에 새로운 노드 삽입
ListNode* insert_next(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *) malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert_last(ListNode *head, int value)
{
    ListNode *temp = head;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    
    p->data = value;
    p->link = NULL;
    
    if (head == NULL)
        head = p;
    else {
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = p;
    }
    return head;
}

ListNode* delete_next(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

ListNode* delete_first(ListNode *head)
{
    ListNode *removed;
    if (head == NULL)
        error("삭제할 항목이 없음");
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete_last(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prevTemp = temp;
    ListNode *removed;
    if (head == NULL)
        error("삭제할 항목이 없음");
    
    if (head->link == NULL) {
        free(temp);
        head = NULL;
    }
    
    else {
        while (temp->link != NULL) {
            prevTemp = temp;
            temp = temp->link;
        }
        removed = temp;
        prevTemp->link = NULL;
        free(temp);
    }
    
    return head;
}

void print_list(ListNode *head)
{
    ListNode *p;
    for (p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

ListNode *search(ListNode *head, int x)
{
    ListNode *p;
    p = head;
    while (p != NULL) {
        if (p->data == x)
            return p;
        p = p->link;
    }
    
    return NULL;
}

ListNode *concat(ListNode *head1, ListNode *head2)
{
    ListNode *p;
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        p = head1;
        while (p->link != NULL)
            p=p->link;
        p->link = head2;
        return head1;
    }
}

ListNode *reverse(ListNode *head)
{
    //순회포인터로 p, q, r을 사용
    ListNode *p, *q, *r;
    
    p = head;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    
    return q;
}

//item이 리스트에 있으면 1을 아니면 0을 반환
int is_in_list(ListNode *head, element item)
{
    if (search(head, item))
        return 1;
    else
        return 0;
}

//단순 연결 리스트에 존재하는 노드의 수를 반환
int get_length(ListNode *head)
{
    int length = 0;
    ListNode *p;
    
    for (p = head; p != NULL; p = p->link)
        length++;
    
    return length;
}

//단순연결 리스트의 모든 데이터 값을 더한 합을 반환
int get_total(ListNode *head)
{
    int sum = 0;
    ListNode *p;
    
    for (p = head; p != NULL; p = p->link)
        sum += p->data;
    return sum;
}

//pos의 위치(0이 첫번재 노드)에 있는 노드의 data를 반환
element get_entry(ListNode *head, int pos)
{
    //pos >= 0 && pos < 길이 여야함.
    if (head == NULL)
        return 0;
    
    else {
        for (int i = 0; i < pos; i++)
            head = head->link;
        
        return head->data;
    }
}
//key의 값을 가지는 노드를 제거
ListNode* delete_by_key(ListNode *head, int key)
{
    ListNode *temp = head;
    ListNode *prevTemp = NULL;
    
    if (!is_in_list(head, key)) {
        printf("잘못된 key\n");
        return head;
    }
    
    while (temp != NULL) {
        if (temp->data == key) {
            if (temp->link == NULL)
                head = delete_last(head);
            else
                prevTemp->link = prevTemp->link->link;
            break;
        }
        prevTemp = temp;
        temp = temp->link;
    }
    
    return head;
}

//pos위치에 value를 갖는 노드를 추가
ListNode* insert_pos(ListNode *head, int pos, element value)
{
    ListNode *p = head;
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    
    for (int i = 0; i < pos - 1; i++)
        p = p->link;
   
    newNode->data = value;
    newNode->link = p->link;
    p->link = newNode;
    
    return head;
    
    /**
        pos 범위값 체크! pos = 0 이고 head == NULL일때도 돌아가나?
        boundary test case
        0 <= pos <= 길이
        1. 비어있고 pos = 0, pos != 0
        2. 비어있지 않고 pos = 0, pos = 중간, pos = 길이
        int index = 0;
        while (index != pos - 1) {
            index++;
            p = p->link;
        }
     */
}

//pos위치의 노드를 삭제
ListNode* delete_pos(ListNode *head, int pos)
{
    int i;
    ListNode *temp = head;
    
    if (get_length(head) - 1 < pos) {
        error("잘못된 pos");
        return head;
    }
    
    if (pos == 0)
        head = delete_first(head);
    
    else {
        for (i = 0; i < pos - 1; i++)
            temp = temp->link;
        head = delete_next(head, temp);
    }
    return head;
}
int main(void)
{
    ListNode *list1 = NULL, *list2 = NULL, *list3;
    
    list1 = insert_first(list1, 10);
    list1 = insert_first(list1, 20);
    list1 = insert_first(list1, 30);
    printf("list1 = "); print_list(list1);
    
    list1 = delete_first(list1); print_list(list1);
    
    list2 = insert_last(list2, 11);
    list2 = insert_last(list2, 22);
    list2 = insert_last(list2, 33);
    list2 = insert_last(list2, 44);
    printf("list2 = "); print_list(list2);
    
    list2 = delete_last(list2); print_list(list2);
    
    list3 = reverse(list2); print_list(list3);
    
    list1 = concat(list1, list3); print_list(list1);
    
    printf("\n-이 이후는 HW1_2에서 추가한 함수들 테스트-\n");
    
    printf("길이는 %d\n", get_length(list1));
    printf("3번째 데이터는 %d\n", get_entry(list1, 2));
    printf("데이터를 모두 더한 값은 %d\n", get_total(list1));
    
    printf("20은 리스트에 %s\n", is_in_list(list1, 20) ? "있습니다" : "없습니다");
    printf("25는 리스트에 %s\n", is_in_list(list1, 25) ? "있습니다" : "없습니다");
    
    list1 = delete_by_key(list1, 20); print_list(list1); //첫번째
    list1 = delete_by_key(list1, 11); print_list(list1); //마지막
    list1 = delete_by_key(list1, 22); print_list(list1); //중간
    
    list1 = insert_pos(list1, 2, 99); print_list(list1);
    list1 = delete_pos(list1, 1); print_list(list1);
    list1 = delete_pos(list1, 0); print_list(list1);
    list1 = delete_pos(list1, 0); print_list(list1);
}
