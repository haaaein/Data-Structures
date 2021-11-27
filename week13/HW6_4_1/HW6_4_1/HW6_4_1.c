#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
int n; // 정점의 개수
int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES]; /* 방문한 정점 표시 */
int previous[MAX_VERTICES];


void graph_init(GraphType *g)
{
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++){
        for(int j = 0; j < MAX_VERTICES; j++){
            if(i == j)
                g->weight[i][j] = 0;
             else
                g->weight[i][j] = INF;
            
        }
    }
}

void insert_edge(GraphType *g, int start, int end, int key)
{
    if( start >= g->n || end >= g->n ){
        fprintf(stderr,"그래프 : 정점 번호 오류");
        return;
    }

    g->weight[start][end] = key;
    g->weight[end][start] = key;
}

void read_graph(GraphType *g, char *filename)
{
    int number, u, v, w;
    FILE *fp;
    fp = fopen(filename, "rt");
    if (fp == NULL)
    {
       printf("file open error!\n");
       return;
    }

    fscanf(fp, "%d\n", &number);
    g->n = number;
    
    while (fscanf(fp, "%d %d %d\n", &u, &v, &w) != EOF) {
        insert_edge(g, u, v, w);
    }
   
    fclose(fp);
}

void print_status(GraphType* g)
{
    for (int i = 0; i < g->n; i++) {
        
        if (distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    
    printf("\n");
    printf("        found:    ");
    
    for (int i = 0; i<g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

void print_path(int start, int end)
{
    int u = end;
    if (start == end) {
        printf("%d -> ", start);
        return;
    }
    else {
        print_path(start, previous[u]);
        printf("%d -> ", u);
    }
    
}

void shortest_path(GraphType* g, int start)
{
    int i, u, v;
    
    for (i = 0; i<g->n; i++) /* 초기화 */
    {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
        previous[i] = start;
    }
    
    found[start] = TRUE; /* 시작 정점 방문 표시 */
    distance[start] = 0;
    
    for (i = 0; i<g->n-1; i++) {
        
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        
        print_path(start, u);
        printf("<%d>\n", distance[u]);
        
        for (v = 0; v < g->n; v++)
            if (!found[v])
                if (distance[u] + g->weight[u][v]<distance[v]) {
                    distance[v] = distance[u] + g->weight[u][v];
                    previous[v] = u;
                }
     }
}

int main(void)
{
    GraphType g;
    
    graph_init(&g);
    read_graph(&g, "input.txt");
    
    shortest_path(&g, 4);

    return 0;
}
