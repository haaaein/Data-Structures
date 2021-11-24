typedef int element;
typedef struct QueueNode {
	element item; 
	struct QueueNode *link; 
} QueueNode;
typedef struct {		
	QueueNode *front, *rear;
} QueueType;
