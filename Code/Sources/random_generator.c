#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph_traversals.h"
#include "random_generator.h"

void random_generate_graph(struct a_graph *graph){
    const int max_no_nodes = 5;
    int iterator_rows;
    int iterator_columns;
    int *adj_mat;
    FILE *file_out;

    srand (time(NULL));
    file_out = fopen("C:/Users/Lascau/Desktop/Project/becheru/graf.txt", "w");

    graph->no_nodes = rand() % max_no_nodes + 1;
    adj_mat = malloc((graph->no_nodes + 5) * (graph->no_nodes + 5) * sizeof(int));
    fprintf(file_out, "%d\n", graph->no_nodes);
    for (iterator_rows = 0; iterator_rows < graph->no_nodes - 1; iterator_rows++)
        for (iterator_columns = iterator_rows + 1; iterator_columns < graph->no_nodes; iterator_columns++){
            int aux = rand() % 2;
            *(adj_mat + iterator_rows * graph->no_nodes + iterator_columns) = aux;
            *(adj_mat + iterator_columns * graph->no_nodes + iterator_rows) = aux;
        }

    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++){
        for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++)
            if (iterator_rows == iterator_columns)
                fprintf(file_out, "%d ", 0);
            else
                fprintf(file_out, "%d ", *(adj_mat + iterator_rows * graph->no_nodes + iterator_columns));

      fprintf(file_out, "\n");
    }

    free(adj_mat);
}
