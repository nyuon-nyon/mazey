#include <stdbool.h>

#ifndef NM_GRAPH_H_
#define NM_GRAPH_H_

#define MAX_VERTICES 100

struct Vertex {
    int x;
    int y;
    int id;
    bool visited;
    unsigned int color;
};

struct Edge {
    int id;
    int from;
    int to;
    int weight;
    int color;
};

struct NM_GRAPH {
    int num_vertices;
    int num_edges;
    struct Vertex *vertices;
    struct Edge *edges;
};

struct NM_GRAPH* NM_GRAPH_INIT(int numVertices);
void NM_END_GRAPH(struct NM_GRAPH *graph);

void NM_REMOVE_EDGE(struct NM_GRAPH *graph, int source, int destination);
void NM_ADD_EDGE(struct NM_GRAPH *graph, int from, int to, int weight, int color);
void NM_ADD_VERTEX(struct NM_GRAPH *graph, int x, int y, int id, int color);

bool NM_IS_EDGE(struct NM_GRAPH *graph, int source, int destination);
int NM_EDGE_WEIGHT(struct NM_GRAPH *graph, int source, int destination);
int NM_EDGE_COLOR(struct NM_GRAPH *graph, int source, int destination);

void NM_PRINT_GRAPH(struct NM_GRAPH *graph);
void NM_PRINT_VERTEX(const struct Vertex *vertex, int vertexId);
void NM_PRINT_EDGE(const struct Edge *edge, int edgeId);

#endif
