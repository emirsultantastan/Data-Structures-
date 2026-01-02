#include <stdio.h>


//BFS
int queue[20], front = -1, rear = -1;
int visited[20]; 
int adj[20][20];


void enqueue(int v) {
    if (rear == 19) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}


int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int start, int n) {
    int i, current;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Sonucu: ");
    while (front <= rear && front != -1) {
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


//DFS
#include <stdio.h>

int visited_dfs[20];
int adj_matrix[20][20];

void dfs(int v, int n) {
    int i;
    visited_dfs[v] = 1; 
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        
        if (adj_matrix[v][i] == 1 && !visited_dfs[i]) {
            dfs(i, n); 
        }
    }
}