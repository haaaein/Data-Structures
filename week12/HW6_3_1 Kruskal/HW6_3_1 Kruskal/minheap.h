#define MAX_ELEMENT 200

typedef struct {
	int key; //weight
	int u;
	int v;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType *h);
int is_empty(HeapType *h);
void insert_min_heap(HeapType *h, element item); 
element delete_min_heap(HeapType *h);
