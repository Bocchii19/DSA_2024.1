#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front, rear;

void createGraph(int n, int m) {
    int u, v;
    for (int i = 0; i < m; i++) {
        printf("Nhập cạnh (u, v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }
}

void bfs(int start, int n) {
    front = rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS từ đỉnh %d: ", start);
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 1; i <= n; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsUtil(int start, int n) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 1; i <= n; i++) {
        if (graph[start][i] && !visited[i]) {
            dfsUtil(i, n);
        }
    }
}

void dfs(int start, int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    printf("DFS từ đỉnh %d: ", start);
    dfsUtil(start, n);
    printf("\n");
}

int main() {
    int n, m, start;

    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &n);
    printf("Nhập số lượng cạnh: ");
    scanf("%d", &m);

    createGraph(n, m);

    printf("Nhập đỉnh bắt đầu duyệt: ");
    scanf("%d", &start);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    bfs(start, n);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    dfs(start, n);

    return 0;
}
