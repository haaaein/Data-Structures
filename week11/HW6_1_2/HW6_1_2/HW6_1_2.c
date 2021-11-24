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

void insert_vertex(GraphType *g, int v)
{
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node;
    if( u >= g->n || v >= g->n ){
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    if (node == NULL) {
        fprintf(stderr, "에러!\n"); return;
    }
    
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
    
    node->vertex = u;
    node->link = g->adj_list[v];
    g->adj_list[v] = node;
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
               printf("%d은 리스트에 없음 \n", item);
     }
}

void delete_edge(GraphType *g, int u, int v)
{
    if( u >= g->n || v >= g->n ){
        fprintf(stderr, "그래프 : 정점 번호 에러");
        return;
    }

    remove_node(&g->adj_list[u], v);
    remove_node(&g->adj_list[v], u);
}

void read_graph(GraphType *g, char *filename)
{
     int number, u, v;
     FILE *fp;
     fp = fopen(filename, "rt");
    if (fp == NULL)
    {
        printf("file open error!\n");
        return;
    }

    fscanf(fp, "%d\n", &number);
    g->n = number;
    while (fscanf(fp, "%d %d\n", &u, &v) != EOF)
        insert_edge(g, u, v);
    
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

    fprintf(fp, "%d\n", g->n);
    for (u = 0; u < g->n; u++)
        for (ptr = g->adj_list[u]; ptr != NULL; ptr = ptr->link)
            fprintf(fp, "%d %d\n", u, ptr->vertex);
    
     if (filename != NULL) fclose(fp);
}

int main(void)
{
    GraphType g;
    graph_init(&g);

    read_graph(&g, "input.txt");
    write_graph(&g, NULL);    // to stdout

    printf("\n");
    insert_edge(&g, 1, 3);
    write_graph(&g, NULL);    // to stdout

    printf("\n");
    delete_edge(&g, 3, 0);
    write_graph(&g, NULL);    // to stdout

    write_graph(&g, "output.txt");
}

