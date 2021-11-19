#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef int element;
typedef struct GraphNode
{
   int vertex;
   struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g)
{
    int v;
    g->n=0;
    for(v=0;v<MAX_VERTICES;v++)
        g->adj_list[v]=NULL;
}

void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node_u, *node_v;
    if( u >= g->n || v >= g->n ){
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    node_u = (GraphNode *)malloc(sizeof(GraphNode));
    if (node_u == NULL) {
        fprintf(stderr, "에러!\n"); return;
    }
     
}

void remove_node(GraphNode **phead, element item) {
     GraphNode *p, *prevp;
     
     if (*phead == NULL)
          printf("삭제할 노드가 없습니다.\n");
     else if ((*phead)->vertex == item) {
          p = *phead;
          *phead = (*phead)->link;
          free(p);
     }
     else {
          p = *phead;
          do {
               prevp = p;
               p = p->link;
          }while (p != NULL && p->vertex != item);
          if (p != NULL) {
               prevp->link = p->link;
               free(p);
          }
          else
               printf("%d 에러 \n", item);
     }
}
void delete_edge(GraphType *g, int u, int v)
{
    GraphNode *node;
    if( u >= g->n || v >= g->n ){
        fprintf(stderr, "그래프 : 정점 번호 에러");
        return;
    }

}

void read_graph(GraphType *g, char *filename)
{
     int number, u, v;
     GraphNode *node;
     FILE *fp;
     fp = fopen(filename, "rt");
    if (fp == NULL)
    {
        printf("file open error!\n");
        return;
    }

     fclose(fp);
}


void write_graph(GraphType *g, char *filename)
{
     int u;
     FILE *fp;
     GraphNode *ptr;
     
     if (filename == NULL) fp = stdout;
     else {
          fp = fopen(filename, "w");
         if (fp == NULL)
         {
             printf("file %s open error!\n", filename);
              return;
         }
     }

     if (filename != NULL) fclose(fp);
}

int main(void)
{
    GraphType g;
    graph_init(&g);

    read_graph(&g, "input.txt");
    write_graph(&g, NULL);    // to stdout

    insert_edge(&g, 1, 3);
    write_graph(&g, NULL);    // to stdout

    delete_edge(&g, 2, 0);
    write_graph(&g, NULL);    // to stdout

    write_graph(&g, "output.txt");
}

