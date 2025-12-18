#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int visited[MAX];
void DFS(int adj[MAX][MAX], int n, int start) {
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, n, i);
        }
    }
}
int main() {
    int n, i, j;
    int adj[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    DFS(adj, n, 0);
    int connected = 1;
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT CONNECTED.\n");
    return 0;
}
