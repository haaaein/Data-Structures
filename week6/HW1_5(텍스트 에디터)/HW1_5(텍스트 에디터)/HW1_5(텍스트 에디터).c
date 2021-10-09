#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR_PER_LINE 100

typedef struct {
    char line[MAX_CHAR_PER_LINE];
} element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void display_text(ListNode *head)
{
    ListNode *p;
    int idx = 1;
    
    if (head == NULL)
        printf("텍스트가 비어있습니다.\n");
    
    printf("--------text edited---------\n");
    for (p = head; p != NULL; p = p->link) {
        printf("(%d) %s", idx, p->data.line);
        idx++;
    }
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

ListNode* insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *) malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert_last(ListNode *head, element value)
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
        printf("삭제할 항목이 없음");
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
        printf("삭제할 항목이 없음");
    
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

ListNode *search(ListNode *head, element x)
{
    ListNode *p;
    p = head;
    while (p != NULL) {
        if (strcmp(p->data.line, x.line))
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
}

//pos위치의 노드를 삭제
ListNode* delete_pos(ListNode *head, int pos)
{
    int i;
   
    ListNode *temp = head;
    
    if (get_length(head) - 1 < pos) {
        printf("잘못된 pos");
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

void print_line(ListNode *head, int num)
{
    ListNode *p = head;
    
    if (p == NULL || (num < 0 || num > get_length(head)))
        printf("출력할 텍스트가 없습니다.\n");
    
    for (int i = 0; i < num; i++) {
        p = p->link;
    }
    printf("(%d) %s", num + 1, p->data.line);
}
        
char askChoice(void)
{
    char choice;
    printf("----------------------------\n");
    printf("a: 텍스트 끝에 라인 추가\n");
    printf("i: 라인 번호로 라인 추가\n");
    printf("d: 라인 번호로 라인 삭제\n");
    printf("v: 라인 번호로 해당 라인 출력\n");
    printf("p: 전체 텍스트 출력\n");
    printf("q: 끝\n");
    
    printf("메뉴 선택: ");
    scanf("%c", &choice);
    return choice;
}

int main(void)
{
    ListNode *list = NULL;
    char choice;
    int lineNb;
    element newElement;
    
    while ((choice = askChoice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("텍스트 끝에 삽입할 라인: ");
                fflush(stdin);
                fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
                list = insert_last(list, newElement);
                display_text(list);
                break;
            case 'i':
                printf("삽입할 라인 번호: ");
                scanf("%d", &lineNb);
                
                printf("삽입할 라인: ");
                fflush(stdin);
                fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
                list = insert_pos(list, lineNb - 1, newElement);
                display_text(list);
                break;
            case 'd':
                printf("삭제할 라인 번호: ");
                scanf("%d", &lineNb);
                list = delete_pos(list, lineNb - 1);
                display_text(list);
                break;
            case 'v':
                printf("출력할 라인 번호: ");
                scanf("%d", &lineNb);
                print_line(list, lineNb - 1);
                break;
            case 'p':
                display_text(list);
        }
        fflush(stdin);
    }
}
