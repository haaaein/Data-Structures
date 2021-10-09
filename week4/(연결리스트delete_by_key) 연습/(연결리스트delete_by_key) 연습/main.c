/*
-1이 나올때까지 일련의 정수를 읽어 *앞*에 차례로 넣어서 연결리스트를 만들고
key 값을 정수로 읽은 후
그 key 값을 연결리스트에서 삭제한 전후의 연결리스트를 출력하는 프로그램을 작성하라.

실행예 #1
10 20 30 40 50 -1 : 일련의 정수 입력
30 : key 입력
50->40->30->20->10->리스트끝 : 만든 연결리스트 출력
50->40->20->10->리스트끝 : key 30을 삭제한 후의 연결리스트 출력

실행예 #1
10 20 30 40 50 -1 : 일련의 정수 입력
70 : key 입력
50->40->30->20->10->리스트끝 : 만든 연결리스트 출력
50->40->30->20->10->리스트끝 : key 70을 삭제한 후(없으므로 삭제가 일어나지 않음)의 연결리스트 출력
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 10     // 리스트의 최대크기

typedef int element;            // 항목의 정의
typedef struct {
    element array[MAX_LIST_SIZE];      // 배열 정의
    int size;          // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType* L)
{
    L->size = 0;
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
    return L->size == 0;
}

// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType* L)
{
    return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType* L)
{
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d->", L->array[i]);
    printf("리스트끝\n");
}


//------------------------------------------------

void insert_first(ArrayListType* L, element item)
{
    int i;
    if (is_full(L))
        printf("리스트 오버플로우\n");
    else {
        for (i = L->size - 1; i >= 0; i--)
            L->array[i + 1] = L->array[i];
        L->array[0] = item;
        L->size++;
    }
}

// 코드 작성 부분
void delete_by_key(ArrayListType* L, element key)
{
    int index = -1;
    int i = 0;
    
    for (int i = 0; i < L->size; i++)
        if (L->array[i] == key)
            index = i;
    
    do {
        if (index != -1) {
            for (int i = index; i < (L->size - 1); i++)
                L->array[i] = L->array[i + 1];
            L->size--;
        }
        
        if (L->array[i] == -1)
            break;
        i++;
    } while (L->array[i] == -1 && index != -1);
}


int main(void)
{
    ArrayListType list1;
    int n, key;

    init(&list1);
    scanf("%d", &n);
    while (n != -1) {
        insert_first(&list1, n);
        scanf("%d", &n);
    }
    scanf("%d", &key);
    print_list(&list1);
    delete_by_key(&list1, key);
    print_list(&list1);
}
