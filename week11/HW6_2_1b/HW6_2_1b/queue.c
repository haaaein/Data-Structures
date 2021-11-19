#include <stdio.h>

typedef int element;    // ����� Ÿ��

typedef struct QueueNode1 {    // ť�� ����� Ÿ��
    element item;
    struct QueueNode1 *link;
} QueueNode1;
typedef struct QueueType1 {        // ť ADT ����
    QueueNode1 *front, *rear;
} QueueType1;

void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
// �ʱ�ȭ �Լ�
void init(QueueType1 *q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType1 *q)
{
	return (q->front==NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType1 *q)
{
	return 0;
}

// ���� �Լ�
void enqueue(QueueType1 *q, element item)
{ 
	QueueNode1 *temp=(QueueNode1 *)malloc(sizeof(QueueNode1));
	if(temp == NULL )
		error("dd");
	else {
		temp->item = item; 		// ������ ����
		temp->link = NULL; 		// ��ũ �ʵ带 NULL
		if( is_empty(q) ){ 		// ť�� �����̸�
			q->front = temp;
			q->rear = temp; 	
		}
		else { 		// ť�� ������ �ƴϸ�
			q->rear->link = temp;  // ������ �߿�
			q->rear = temp; 
		} 	
	}
}

// ���� �Լ�
element dequeue(QueueType1 *q)
{ 
 	QueueNode1 *temp = q->front;
 	element item; 
//	if( is_empty(q) )			// �������
//		error("ť�� ��� �����ϴ�");
//	else {
		item = temp->item; 		// �����͸� ������.
		q->front = q->front->link; // front�� ������带 ����Ű���� �Ѵ�.
		if( q->front == NULL ) 	// ���� ����
			q->rear = NULL;
		free(temp); 			// �����޸� ����
		return item; 			// ������ ��ȯ
//	}
} 
