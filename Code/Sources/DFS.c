///\file DFS.c
#include <stdlib.h>
#include "graph_traversals.h"

void DFS(struct a_graph *graph, int start_node){
    ///\fn void DFS(struct a_graph *graph, int start_node)
    ///\brief a function that apply depth first search on an arbitrary node called start_node
    ///\param *graph a pointer to a structure which contains the number of nodes, the adjacency matrix and a list of visited nodes
    ///\param start_node is an arbitrary node

    int *stack;
    int no_elements_stack;
    int iterator_nodes;
    int temp_node;

    stack = calloc(graph->no_nodes ,sizeof(int));
    no_elements_stack = 1;
    stack[no_elements_stack] = start_node;
    *(graph->is_visited + start_node) = 1;

    while (no_elements_stack > 0){
        temp_node = stack[no_elements_stack];
        no_elements_stack--;
        for (iterator_nodes = 1; iterator_nodes <= graph->no_nodes; iterator_nodes++)
            if (*(graph->is_visited + iterator_nodes) == 0 && *(graph->adj_matrix + (iterator_nodes - 1) * graph->no_nodes + temp_node - 1) == 1){
                *(graph->is_visited + iterator_nodes) = 1;
                no_elements_stack++;
                stack[no_elements_stack] = iterator_nodes;
            }
    }

    free(stack);
}
