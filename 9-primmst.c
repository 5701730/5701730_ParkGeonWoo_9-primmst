#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 10
#define INF INT_MAX

typedef struct {
    int n;  
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) {
    g->n = MAX_VERTICES;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->weight[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void GenerateGraph(GraphType* g) {
    
    int edges[][3] = {
        {0, 1, 1},  
        {1, 4, 2},  
        {4, 3, 3},  
        {3, 2, 4},  
        {2, 7, 5},  
        {7, 6, 6},  
        {6, 5, 7},  
        {5, 9, 8},  
        {9, 8, 9}   
    };
    int edge_count = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edge_count; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        g->weight[u][v] = w;
        g->weight[v][u] = w;
    }
}

void FindPrimMST(GraphType* g) {
    bool selected[MAX_VERTICES] = { false };
    int mst_weight = 0;
    int edge_count = 0;

    // 첫 번째 선택
    selected[0] = true;  // 정점 1부터 시작 (0번 인덱스)
    printf("Prim MST Algorithm\n");
    printf("정점 1 추가\n");  // 첫 번째 정점을 선택할 때 출력

    while (edge_count < g->n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < g->n; i++) {
            if (selected[i]) {
                for (int j = 0; j < g->n; j++) {
                    if (!selected[j] && g->weight[i][j] < min) {
                        min = g->weight[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            // 선택된 정점 추가
            printf("정점 %d 추가\n", v + 1);
            selected[v] = true;
            mst_weight += min;
            edge_count++;
        }
    }

    
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    GenerateGraph(g);
    FindPrimMST(g);
    free(g);
    return 0;
}


