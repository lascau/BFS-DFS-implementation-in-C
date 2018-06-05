///\file main.c
#include <stdio.h>
#include <stdlib.h>
#include "graph_traversals.h"
#include "random_generator.h"

void read_adj_matrix(struct a_graph *graph){
     ///\brief a function that reads the adjacency matrix from a file
     ///\param struct a_graph *graph is a pointer to a structure which contains the number of nodes, the adjacency matrix and a list of visited nodes
    int iterator_rows;
    int iterator_columns;
    FILE *file_in;

    file_in = fopen("graf.txt", "r");

    fscanf(file_in, "%d", &graph->no_nodes);
    graph->is_visited = calloc(graph->no_nodes, sizeof(int));
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes, sizeof(int));
    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++)
        for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++)
            fscanf(file_in, "%d", graph->adj_matrix + iterator_rows * graph->no_nodes + iterator_columns);

    fclose(file_in);
}

int no_connected_components(struct a_graph *graph){
    ///\brief a function that returns the number of connected components in a given graph
    ///\param struct a_graph *graph is a pointer to a structure which contains the number of nodes, the adjacency matrix and a list of visited nodes

    int no_cc = 0;
    int iterator_nodes;

    for (iterator_nodes = 0; iterator_nodes < graph->no_nodes; iterator_nodes++)
        if (*(graph->is_visited + iterator_nodes) == 0){
            no_cc++;
            BFS(graph, iterator_nodes);
        }
    return no_cc;
}

void delete_graph(struct a_graph *graph){
        ///\brief a function that deallocates memory used for storing the graph
        ///\param struct a_graph *graph is a pointer to a structure which contains the number of nodes, the adjacency matrix and a list of visited nodes

    free(graph->adj_matrix);
    free(graph->is_visited);
    free(graph);
}

int main()
{
     ///\fn int main()
     ///\var *graph is a pointer to a structure which contains the number of nodes, the adjacency matrix and a list of visited nodes

    struct a_graph *graph;

    graph = malloc(sizeof(struct a_graph));
    random_generate_graph(graph);
    read_adj_matrix(graph);
    printf("The number of connected components is: %d", no_connected_components(graph));

    delete_graph(graph);
    return 0;
}
