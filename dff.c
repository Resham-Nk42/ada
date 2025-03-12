#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


struct Graph {
    int vertices;                         
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; 
};


void createGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    
  
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}


void addEdge(struct Graph* g, int u, int v) {
    g->adjMatrix[u][v] = 1; 
}


int topologicalSort(struct Graph* g) {
    int inDegree[MAX_VERTICES] = {0};    
    int topOrder[MAX_VERTICES];          
    int queue[MAX_VERTICES], front = 0, rear = 0;  
    int count = 0; 

    
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            if (g->adjMatrix[i][j] == 1) {
                inDegree[j]++; 
            }
        }
    }

   
    for (int i = 0; i < g->vertices; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i; 
        }
    }


    while (front != rear) {
        int current = queue[front++];  
        topOrder[count++] = current;   

        
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[current][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

   
    if (count != g->vertices) {
        printf("There exists a cycle in the graph. Topological sort not possible.\n");
        return 0; 
    }

    
    printf("Topological Sort: ");
    for (int i = 0; i < g->vertices; i++) {
        printf("%d ", topOrder[i]);
    }
    printf("\n");

    return 1; 
}


int main() {
    struct Graph g;
    int vertices, edges, u, v;

    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    createGraph(&g, vertices); 
    
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    
    printf("Enter the edges (u v) where there is an edge from u to v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v); 
    }

   
    topologicalSort(&g);

    return 0;
}
