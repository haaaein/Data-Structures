#include <stdio.h>
#include <stdlib.h>
//#include "queue.h"
#include "queue.c"

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

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
    if( ((g->n)+1) > MAX_VERTICES ){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
    
    node->vertex = u;
    node->link = g->adj_list[v];
    g->adj_list[v] = node;
}
int visited[MAX_VERTICES];

void bfs_list(GraphType *g, int v)
{
    GraphNode *w;
    QueueType1 q;
    init(&q);
    visited[v] = TRUE;
    enqueue(&q, v);
    while(!is_empty(&q)){
         v = dequeue(&q);
        for(w=g->adj_list[v]; w; w = w->link)
              if(!visited[w->vertex]){
                    visited[w->vertex] = TRUE;
                    enqueue(&q, w->vertex);
                  printf("<%d %d>\n", v, w->vertex);
              }
    }
}

void dfs_list(GraphType *g, int v)
{
    GraphNode *w;
    visited[v] = TRUE;
    
    for (w = g->adj_list[v]; w != NULL; w = w->link)
        if (!visited[w->vertex]) {
            printf("<%d %d>\n", v, w->vertex);
            dfs_list(g, w->vertex);
        }
}

void read_graph(GraphType *g, char *filename)
{
    int number = 0, u, v;
    FILE *fp;
    fp = fopen(filename, "rt");
    
    if (fp == NULL)
    {
        printf("file %s open error!\n", filename);
        return;
    }
    
    fscanf(fp, "%d\n", &number);
    for (int i = 0; i < number; i++)
        insert_vertex(g, i);
    
    while (fscanf(fp, "%d %d\n", &u, &v) != EOF) {
        insert_edge(g, u, v);
        insert_edge(g, v, u);
    }
    
    fclose(fp);
}

int main(void)
{
     GraphType graph;
     int v;

     graph_init(&graph);
     read_graph(&graph, "infile.txt");
     
     printf("Enter 정점:");
     scanf("%d", &v);
     
     dfs_list(&graph, v);
}
