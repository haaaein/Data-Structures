#include <stdio.h>
#include "queue.h" // <---------------------------------

// ���� �Լ�
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
// �ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front==NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return 0;
}

// ���� �Լ�
void enqueue(QueueType *q, element item)
{ 
	QueueNode *temp=(QueueNode *)malloc(sizeof(QueueNode)); 
	if(temp == NULL )
		error("�޸𸮸� �Ҵ��� �� �����ϴ�");
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
element dequeue(QueueType *q) 
{ 
 	QueueNode *temp = q->front;
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