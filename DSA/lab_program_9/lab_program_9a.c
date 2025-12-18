#include <stdio.h>
#include <stdlib.h>
#define MAX 20   
int queue[MAX], front = -1, rear = -1;
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}
int isEmpty() {
    return (front == -1 || front > rear);
}
void BFS(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int i, current;
    enqueue(start);
    visited[start] = 1;
    while (!isEmpty()) {
        current = dequeue();
        printf("%d ", current);
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int n, i, j, start;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("BFS Traversal starting from vertex %d: ", start);
    BFS(adj, visited, start, n);
    return 0;
}
