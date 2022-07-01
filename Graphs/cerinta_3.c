#include "utils.h"

/**
 * TODO:   Implementati o functie ce ce genereaza matricea drumurilor unui graf reprezentat cu 
 * ajutorul matricei de adiacenta
 * @note   
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - o matrice reprezentand matricea drumurilor
 */
int** findPaths(graph_matrix* graph) {

    int i, j, k;
    int **pathMatrix;
    
    pathMatrix = (int**)malloc(graph->V * sizeof(int*));

    for(i=0; i<graph->V; i++){
            pathMatrix[i] = (int*)malloc(sizeof(int));
            pathMatrix[i] = graph -> matrix[i];
    }
    
    for(i=0; i<graph->V; i++){
        for(j=0; j<graph->V; j++){
            pathMatrix[i][j] = graph -> matrix[i][j];
        }
    }

    for(k=0; k < graph->V; k++){
        for(i=0; i < graph->V; i++){
            for(j=1; j < graph->V; j++){
                pathMatrix[i][j] = pathMatrix[i][j] | ((pathMatrix[i][k]!=0 && pathMatrix[k][j]!=0) ? 1 : 0);
            }
        }
    }

    return pathMatrix;
}