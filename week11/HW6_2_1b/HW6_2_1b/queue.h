typedef int element;	// ����� Ÿ��
typedef struct QueueNode1 {	// ť�� ����� Ÿ��
	element item; 
	struct QueueNode1 *link;
} QueueNode1;
typedef struct {		// ť ADT ����
	QueueNode1 *front, *rear;
} QueueType1;
