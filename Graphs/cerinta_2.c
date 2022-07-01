#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat prin liste de adiacenta 
 * intr-unul reprezentat cu ajutorul unei matrice de adiacenta
 * @note   Nodurile trebuie indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
graph_matrix* listToMatrix(graph_list* graph) {
    int i;
    graph_matrix* adjMatrix = (graph_matrix*)malloc(sizeof(graph_matrix));

    if(adjMatrix == NULL){
        return NULL;
    }

    adjMatrix -> E = graph -> E;
    adjMatrix -> V = graph -> V;

    adjMatrix -> matrix = (int**)malloc(graph->V * sizeof(int*));

    for(i=0; i<graph->V; i++){
        adjMatrix -> matrix[i] = (int*)calloc(graph->V, sizeof(int));

        node* position = graph -> listHeads[i];
        while(position != NULL){
            adjMatrix -> matrix[i][position->vertexNr] = 1;
            position = position -> next;
        }
    }

    return adjMatrix;
}


/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_list(graph_list** graph) {
    int i;

    for(i=0; i<(*graph)->V; i++){
        free((*graph) -> listHeads[i]);
    }

    free((*graph) -> listHeads);
    free((*graph));
    *graph = NULL;
}


void print_graph_matrix(graph_matrix* graph) {
    int i, j;
    
    for(i=0; i<graph->V; i++){
        for(j=0; j<graph->V; j++){
            printf(" %d", graph->matrix[i][j]);
        }
        printf("\n");
    }
}