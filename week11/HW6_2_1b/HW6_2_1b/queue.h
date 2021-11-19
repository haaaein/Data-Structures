typedef int element;	// 요소의 타입
typedef struct QueueNode1 {	// 큐의 노드의 타입
	element item; 
	struct QueueNode1 *link;
} QueueNode1;
typedef struct {		// 큐 ADT 구현
	QueueNode1 *front, *rear;
} QueueType1;
