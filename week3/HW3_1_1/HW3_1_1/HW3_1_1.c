#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
    char name[1024];
    char gender;
} element;

typedef struct {
    int front;
    int rear;
    element queue[MAX_QUEUE_SIZE];
} QueueType;

//오류함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->rear = 0;
    q->front = 0;
}

int is_full(QueueType *q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다.");
    
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

element peek(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q)
{
    return ((q->rear - q->front) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void print_queue(QueueType *mq, QueueType *wq)
{
    int sizeM, sizeF;
    sizeM = get_count(mq);
    sizeF = get_count(wq);
    
    printf("남성 대기자 %d명: ", sizeM);
    int idx = (mq->front + 1) % MAX_QUEUE_SIZE;

    for (int i = 0; i < sizeM; i++)
    {
        printf("%s ", mq->queue[idx].name);
        idx = (idx + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
    printf("여성 대기자 %d명: ", sizeF);
    idx = (wq->front + 1) % MAX_QUEUE_SIZE;
    for (int i = 0; i < sizeF; i++)
    {
        printf("%s ", wq->queue[idx].name);
        idx = (idx + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main(void)
{
    QueueType manQ, womanQ;
    element newPerson;
    char choose = 'q';
    
    init_queue(&manQ);
    init_queue(&womanQ);
    
    printf("미팅 주선 프로그램입니다.\n");
    
    do {
        printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>: ");
        scanf("%c", &choose);
        getchar();
        
        if (choose == 'i') {
            printf("이름을 입력: ");
            scanf("%s", newPerson.name);
            getchar();
            printf("성별을 입력<m of f>: ");
            scanf("%c", &newPerson.gender);
            getchar();
            
            if (newPerson.gender == 'm')
                enqueue(&manQ, newPerson);
            else
                enqueue(&womanQ, newPerson);
         
            if (!is_empty(&manQ) && !is_empty(&womanQ)) {
                printf("커플이 탄생했습니다! %s과 %s\n",
                       manQ.queue[manQ.front + 1].name, womanQ.queue[womanQ.front + 1].name);
                dequeue(&manQ);
                dequeue(&womanQ);
            }
            
            else {
                printf("아직 대상자가 없습니다. 기다려주십시요.\n");
            }
        }
        
        else if (choose == 'c') {
            print_queue(&manQ, &womanQ);
        }
            
        else if (choose == 'q') {
            break;
        }
    } while (choose != 'q');
}


