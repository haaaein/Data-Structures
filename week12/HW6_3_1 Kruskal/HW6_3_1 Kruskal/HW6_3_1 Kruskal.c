#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 9999

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g)
{
    g->n = 0;
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adj_mat[i][j] = INF;
            
        }
    }
}

/*  */
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
        g->adj_mat[u][v] = w;
        g->adj_mat[u][v] = w;
    }
   
    fclose(fp);
}

/*  */
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
        for (j = i; j < g->n; j++) {
            if (g->adj_mat[i][j] != INF) {
                fprintf(fp, "%d %d %d\n", i, j, g->adj_mat[i][j]);
            }
        }
    }
    
    if (filename != NULL) fclose(fp);
}
    
void insert_heap_edge(HeapType *h, int u, int v, int weight)
{

    element e;
    e.u = u;
    e.v = v;
    e.key = weight;
    insert_min_heap(h, e);
}

void insert_all_edges(HeapType *h, GraphType *g)
{
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            insert_heap_edge(h, i, j, g->adj_mat[i][j]);
        }
    }
    
}

void kruskal(GraphType *g, GraphType *t)
{
    int edge_accepted = 0;
    int uset, vset;
    element e;
    HeapType h;
    
    init(&h);
    insert_all_edges(&h, g);
    set_init(g->n);

    printf("선택된 간선<순서대로>:\n");
    while (edge_accepted < (g->n - 1)) {
        e = delete_min_heap(&h);
        uset = set_find(e.u);
        vset = set_find(e.v);
        
        if (uset != vset) {
            edge_accepted++;
            set_union(uset, vset);
            printf("%d %d %d \n", e.u, e.v, e.key);
            t->adj_mat[e.u][e.v] = e.key;
        }
        
    }
}

int main()
{
    GraphType g, t;
    
    graph_init(&g);
    read_graph(&g, "input.txt");
    //read_graph(&g, "input2.txt");

    graph_init(&t);
    t.n = g.n;
        
    kruskal(&g, &t);
    
    printf("파일로 출력:\n");
    write_graph(&t, "output.txt");
    write_graph(&t, NULL);    // to stdout
}
