#include "NM_graph.h"
#include "NM_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define numVertices 20

int main() {
    struct NM_GRAPH *graph = NM_GRAPH_INIT(numVertices);
    if (graph == NULL) {
        printf("Error creating graph\n");
        return 1;
    }

    // Randomly select some edges to add
    srand(time(NULL));
    int numEdgesToAdd = numVertices * (numVertices - 1) / 4; // Adjust as needed
    for (int k = 0; k < numEdgesToAdd; ++k) {
        int i = rand() % numVertices;
        int j = rand() % numVertices;
        if (i != j) {
            NM_ADD_EDGE(graph, i, j, 1, 0); // graph, from, to, weight, color
        }
    }

    // Print graph
    NM_PRINT_GRAPH(graph);

    // Run BFS
    int startingVertex = rand() % numVertices; // Choose a random starting vertex
    NM_BFS(graph, startingVertex);

    // Clean up
    NM_END_GRAPH(graph);

    return 0;
}
