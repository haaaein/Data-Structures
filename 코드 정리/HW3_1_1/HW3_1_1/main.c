#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3 //3으로 설정
#define MAX_STRING 100 // 추가

typedef struct { //수정
     char name[MAX_STRING];
} element;

typedef struct {
    element  queue[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;
//
void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}
// 초기화 함수
void init(QueueType *q)
{
    q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(QueueType *q, element item)
{
      if( is_full(q) )
        error("큐가 포화상태입니다");
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType *q)
{
       if( is_empty(q) )
        error("큐가 공백상태입니다");
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}
// 보기 함수
element peek(QueueType *q)
{
       if( is_empty(q) )
        error("큐가 공백상태입니다");
    return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q)
{
    return ((q->rear - q->front) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void print_queue(QueueType *q) // 추가, 20141016 수정
{
    int size;
    size = get_count(q);
    
    int idx = (q->front + 1) % MAX_QUEUE_SIZE;

    for (int i = 0; i < size; i++)
    {
        printf("%s ", q->queue[idx].name);
        idx = (idx + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

void try_match(char *name, QueueType *partnerQ, QueueType *myQ) //추가 부분: 더 좋은 함수 이름??
{
    element person;
    strcpy(person.name, name);
    enqueue(myQ, person);
    
    if (!is_empty(partnerQ) && !is_empty(myQ)) {
        printf("커플이 탄생했습니다! %s과 %s\n", myQ->queue[myQ->front + 1].name, partnerQ->queue[partnerQ->front].name);
        dequeue(myQ);
        dequeue(partnerQ);
    }
    else {
        printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담 기회를 이용\n");
    }
}

int main(void)
{
     QueueType manQ, womanQ;
     char choice;
     char name[MAX_STRING];
     char gender;

     init(&manQ);
     init(&womanQ);

     printf("미팅 주선 프로그램입니다.\n");
     
     printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit):");
     scanf("%c", &choice);
 
     while (choice != 'q') {
          switch(choice) {
          case 'i':
               printf("이름을 입력:");
               scanf("%s", name);
               fflush(stdin);
               printf("성별을 입력(m or f):");
               scanf("%c", &gender);
               if (gender == 'm')
                    try_match(name, &womanQ, &manQ);
               else
                    try_match(name, &manQ, &womanQ);
               break;
          case 'c':
               printf("남성 대기자 %d명: ", get_count(&manQ));
               print_queue(&manQ);
               printf("여성 대기자 %d명: ", get_count(&womanQ));
               print_queue(&womanQ);
          }
          fflush(stdin);
          printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit):");
          scanf("%c", &choice);
     }
}

