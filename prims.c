#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], et[MAX][2], vis[MAX], n, e = 0, sum = 0;

void prims() {
    int i, j, u, v, min;
    vis[0] = 1;
    e = 0;
    for (i = 0; i < n; i++) {
        min = INF;
        u = v = -1;
        for (j = 0; j < n; j++) {
            if (vis[j]) {
                for (int k = 0; k < n; k++) {
                    if (!vis[k] && cost[j][k] < min) {
                        min = cost[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            et[e][0] = u;
            et[e][1] = v;
            vis[v] = 1;
            sum += min;
            e++;
        }
    }
}

int main() {
    int i, j, edges, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cost[i][j] = INF;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (u v w):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }
    prims();
    printf("Edges of the minimum spanning tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d\n", et[i][0], et[i][1]);
    }
    printf("Total weight = %d\n", sum);
    return 0;
}
