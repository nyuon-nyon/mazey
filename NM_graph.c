#include "NM_graph.h"
#include <stdio.h>
#include <stdlib.h>


struct NM_GRAPH* NM_GRAPH_INIT(int numVertices) {
    struct NM_GRAPH *graph = (struct NM_GRAPH*)malloc(sizeof(struct NM_GRAPH));

    if (graph == NULL) {
        return NULL;
    }

    graph->num_vertices = numVertices;
    graph->num_edges = 0;

    graph->vertices = (struct Vertex*)malloc(numVertices * sizeof(struct Vertex));
    if (graph->vertices == NULL) {
        free(graph);
        return NULL;
    }

    for (int i = 0; i < numVertices; ++i) {
        graph->vertices[i].x = 0;
        graph->vertices[i].y = 0;
        graph->vertices[i].id = i;
        graph->vertices[i].visited = false;
        graph->vertices[i].color = 0;
    }

    graph->edges = NULL;

    return graph;
}

void NM_END_GRAPH(struct NM_GRAPH *graph) {
    if (graph == NULL) {
        return;
    }

    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

void NM_ADD_EDGE(struct NM_GRAPH *graph, int from, int to, int weight, int color) {
    if (graph == NULL || from < 0 || from >= graph->num_vertices ||
        to < 0 || to >= graph->num_vertices) {
        return;
    }

    graph->num_edges++;

    graph->edges = (struct Edge *)realloc(graph->edges, graph->num_edges * sizeof(struct Edge));


    struct Edge newEdge;
    newEdge.id = graph->num_edges - 1; // Assign a unique ID
    newEdge.from = from;
    newEdge.to = to;
    newEdge.weight = weight;
    newEdge.color = color;

    graph->edges[newEdge.id] = newEdge;
}

void NM_ADD_VERTEX(struct NM_GRAPH *graph, int x, int y, int id, int color) {
    if (graph == NULL) {
        return;
    }

    graph->num_vertices++;

    graph->vertices = (struct Vertex *)realloc(graph->vertices, graph->num_vertices * sizeof(struct Vertex));

    struct Vertex newVertex;
    newVertex.x = x;
    newVertex.y = y;
    newVertex.id = id;
    newVertex.visited = false;
    newVertex.color = color;

    graph->vertices[newVertex.id] = newVertex;
}

void NM_REMOVE_EDGE(struct NM_GRAPH *graph, int from, int to) {
        if (graph == NULL || from < 0 || from >= graph->num_vertices ||
        to < 0 || to >= graph->num_vertices) {

        return;
    }


    int edgeIndex = -1;
    for (int i = 0; i < graph->num_edges; i++) {
        if (graph->edges[i].from == from && graph->edges[i].to == to) {
            edgeIndex = i;
            break;
        }
    }

    if (edgeIndex != -1) {

        for (int i = edgeIndex; i < graph->num_edges - 1; i++) {
            graph->edges[i] = graph->edges[i + 1];
        }


        graph->num_edges--;


        graph->edges = (struct Edge *)realloc(graph->edges, graph->num_edges * sizeof(struct Edge));
    }
}

void NM_REMOVE_VERTEX(struct NM_GRAPH *graph, int vertexId) {
        if (graph == NULL || vertexId < 0 || vertexId >= graph->num_vertices) {
        return;
    
    }
}

bool NM_IS_EDGE(struct NM_GRAPH *graph, int from, int to) {

        if (graph == NULL || from < 0 || from >= graph->num_vertices ||
        to < 0 || to >= graph->num_vertices) {

        return false;
    }


    for (int i = 0; i < graph->num_edges; i++) {
        if ((graph->edges[i].from == from && graph->edges[i].to == to) ||
            (graph->edges[i].from == to && graph->edges[i].to == from)) {
            return true;
        }
    }

    return false;
};

int NM_EDGE_WEIGHT(struct NM_GRAPH *graph, int from, int to) {
        if (graph == NULL || from < 0 || from >= graph->num_vertices ||
        to < 0 || to >= graph->num_vertices) {

        return -1;
    }


    for (int i = 0; i < graph->num_edges; i++) {
        if ((graph->edges[i].from == from && graph->edges[i].to == to) ||
            (graph->edges[i].from == to && graph->edges[i].to == from)) {
            return graph->edges[i].weight; // Return the weight of the edge
        }
    }

    return -1; 
};

int NM_EDGE_COLOR(struct NM_GRAPH *graph, int from, int to) {
        if (graph == NULL || from < 0 || from >= graph->num_vertices ||
        to < 0 || to >= graph->num_vertices) {
        
        return -1; 
    }


    for (int i = 0; i < graph->num_edges; i++) {
        if ((graph->edges[i].from == from && graph->edges[i].to == to) ||
            (graph->edges[i].from == to && graph->edges[i].to == from)) {
            return graph->edges[i].color;
        }
    }

    return -1;
};

void NM_PRINT_VERTEX(const struct Vertex *vertex, int vertexId) {
    printf("Vertex %d: id=%d, x=%d, y=%d, color=%d\n",
           vertexId, vertex->id, vertex->x, vertex->y, vertex->color);
}

void NM_PRINT_EDGE(const struct Edge *edge, int edgeId) {
    printf("Edge %d: id=%d, from=%d, to=%d, weight=%d, color=%d\n",
           edgeId, edge->id, edge->from, edge->to, edge->weight, edge->color);
}

void NM_PRINT_GRAPH(struct NM_GRAPH *graph) {

  if (graph == NULL) {
    printf("NM_GRAPH is NULL.\n"); 
    return;
  }

  int i, j;

  // Print column headers (vertex labels)
  printf("   ");
  for (i = 0; i < graph->num_vertices; i++) {
    printf("%2d ", i);
  }
  printf("\n");

  // Print separator line
  printf("  +");
  for (i = 0; i < graph->num_vertices; i++) {
    printf("---");
  }
  printf("\n");

  for (i = 0; i < graph->num_vertices; i++) {
    // Print row header (vertex label)
    printf("%2d|", i);

    for (j = 0; j < graph->num_vertices; j++) {
        if (NM_IS_EDGE(graph, i, j)) {
            printf(" # ");
        } else {
            printf(" . ");
        }
    }
    printf("\n");
  }

  printf("\n");

}

