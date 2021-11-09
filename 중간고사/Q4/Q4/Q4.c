#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
#define MAX_STRING 100

typedef struct {
    char name[MAX_STRING];
    int age;
} element;

typedef struct {
    element  queue[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;
//
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("≈•∞° ∆˜»≠ªÛ≈¬¿‘¥œ¥Ÿ");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
    //if (is_empty(q))
        //error("≈•∞° ∞¯πÈªÛ≈¬¿‘¥œ¥Ÿ");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

void print_queue(QueueType* q)
{
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%s ", q->queue[i].name);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("end\n");
}

int main(void)
{
    QueueType AQ, BQ;
    int n;
    element ele, eleA, eleB;
    init(&AQ);
    init(&BQ);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", ele.name, &ele.age);
        enqueue(&AQ, ele);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s %d", ele.name, &ele.age);
        enqueue(&BQ, ele);
    }

    int i = 0;
    while (i < n) {
        if (AQ.queue[AQ.front + 1].age <= BQ.queue[BQ.front + 1].age) {
            eleA = dequeue(&AQ);
            eleB = dequeue(&BQ);
            enqueue(&BQ, eleB);
            printf("%s %d\n", eleA.name, eleA.age);
        }

        else {
            eleB = dequeue(&BQ);
            eleA = dequeue(&AQ);
            enqueue(&AQ, eleA);
            printf("%s %d\n", eleB.name, eleB.age);
        }
        i++;
    }

    print_queue(&AQ);
    print_queue(&BQ);
}
