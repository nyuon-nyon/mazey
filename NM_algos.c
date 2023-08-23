#include <stdio.h>
#include <stdlib.h>
#include "NM_algos.h"
#include "NM_graph.h"

void NM_BFS(struct NM_GRAPH *graph, int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    queue[++rear] = startVertex;
    graph->vertices[startVertex].visited = true;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("Visited vertex: %d\n", currentVertex);

        for (int i = 0; i < graph->num_edges; ++i) {
            if (graph->edges[i].from == currentVertex && !graph->vertices[graph->edges[i].to].visited) {
                queue[++rear] = graph->edges[i].to;
                graph->vertices[graph->edges[i].to].visited = true;
            }
        }
    }
}