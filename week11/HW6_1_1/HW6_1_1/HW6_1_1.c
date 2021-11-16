#include <stdio.h>
#define MAX_VERTICES 50
#define TRUE 1;
#define FALSE 0;

int visited[MAX_VERTICES][MAX_VERTICES]; // 전역변수는 0 으로 자동 초기화

typedef struct GraphType {
     int n;
     int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g) // 그래프 초기화
{
    int r,c;
    g->n = 0;
    for(r = 0; r < MAX_VERTICES; r++)
        for(c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c]=0;
}

void insert_edge(GraphType *g, int start, int end) // 간선 삽입 연산
{
     if( start >= g->n || end >= g->n ){
         fprintf(stderr,"삽입 : 그래프: 정점 번호 오류\n");
         return;
     }
     g->adj_mat[start][end] = 1;
     g->adj_mat[end][start] = 1;
}

void insert_vertex(GraphType *g, int v) // 정점 삽입 연산
{
     if (((g->n) + 1) > MAX_VERTICES) {
         fprintf(stderr, "그래프 정점의 개수 초과");
         return;
     }
     g->n++;
}

void delete_edge(GraphType *g, int start, int end)
{
    if( start >= g->n || end >= g->n ){
        fprintf(stderr,"그래프: 정점 번호 오류");
        return;
    }
     
    g->adj_mat[start][end] = 0;
    g->adj_mat[end][start] = 0;
}
//
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
    
    fscanf(fp, "%d", &number);
    for (int i = 0; i < number; i++)
        insert_vertex(g, i);
    
    while (fscanf(fp, "%d %d", &u, &v) != EOF)
        insert_edge(g, u, v);
    
    fclose(fp);
}

void write_graph(GraphType *g, char *filename)
{
    int i, j;
    FILE *fp;
     
    if (filename == NULL)
        fp = stdout;
    
    else {
        fp = fopen(filename, "wt");
        if (fp == NULL)
        {
            printf("file %s open error!\n", filename);
            return;
        }
    }
    
    fprintf(fp, "%d\n", g->n);
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            if (g->adj_mat[i][j] == 1 && g->adj_mat[j][i] == 1 && visited[i][j] == 0) {
                fprintf(fp, "%d %d\n", i, j);
                visited[i][j] = 1;
                visited[j][i] = 1;
            }
        }
    }
    
    if (filename != NULL) fclose(fp);
}

void visited_init()
{
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++)
        for (j = 0; j < MAX_VERTICES; j++)
            visited[i][j] = 0;
}

int main(void)
{
    GraphType g;
    graph_init(&g);
    read_graph(&g, "input.txt");
    printf("정점의 개수 %d\n", g.n);
    printf("--1--\n\n");
    visited_init();
    write_graph(&g, NULL);    // to stdout

    printf("--2--\n\n");
    insert_edge(&g, 1, 3);
    visited_init();
    write_graph(&g, NULL);    // to stdout

    printf("--3--\n\n");
    delete_edge(&g, 2, 0);
    visited_init();
    write_graph(&g, NULL);    // to stdout

    printf("--4--\n\n");
    visited_init();
    write_graph(&g, "output.txt");
}

     
    
