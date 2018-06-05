#ifndef GRAPH_TRAVERSALS_H_INCLUDED
#define GRAPH_TRAVERSALS_H_INCLUDED

struct a_graph {
    int no_nodes;
    int *is_visited;
    int *adj_matrix;
};

void DFS(struct a_graph *graph, int start_node);
void BFS(struct a_graph *graph, int start_node);

#endif // GRAPH_TRAVERSALS_H_INCLUDED
