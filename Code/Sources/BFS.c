#include <stdlib.h>
#include "graph_traversals.h"

void BFS(struct a_graph *graph, int start_node){
    int *queue;
    int front;
    int back;
    int iterator_nodes;
    int temp_node;

    queue = calloc(graph->no_nodes, sizeof(int));
    front = back = 0;
    queue[front] = start_node;
    *(graph->is_visited + start_node) = 1;

    while (front <= back){
        temp_node = queue[front];
        front++;
        for (iterator_nodes = 0; iterator_nodes < graph->no_nodes; iterator_nodes++)
            if (*(graph->is_visited + iterator_nodes) == 0 && *(graph->adj_matrix + iterator_nodes * graph->no_nodes + temp_node) == 1){
                *(graph->is_visited + iterator_nodes) = 1;
                back++;
                queue[back] = iterator_nodes;
            }
    }
    free(queue);
}
