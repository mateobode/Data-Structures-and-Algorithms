#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati algoritmul Floyd-Warshall pentru un graf cu matricea de adiacenta data
 * @param  g: graful dat
 * @retval - Matricea costurilor pentru toate nodurile
 */
int **Floyd_Warshall(Graph *g){
    
    int i, j, k;
    int **pathMatrix;
    
    pathMatrix = (int**)malloc(g->V * sizeof(int*));

    for(i=0; i<g->V; i++){
            pathMatrix[i] = (int*)calloc(g->V, sizeof(int));
    }
    
    for(i=0; i<g->V; i++){
        for(j=0; j<g->V; j++){
           if(g->mat[i][j] == 0)
                pathMatrix[i][j] = INF_MAX;
           else
                pathMatrix[i][j] = g -> mat[i][j];
        }
    }

    for(k=0; k < g->V; k++){
        for(i=0; i < g->V; i++){
            for(j=0; j < g->V; j++){
                if(pathMatrix[i][k] + pathMatrix[k][j] < pathMatrix[i][j])
                    pathMatrix[i][j] = pathMatrix[i][k] + pathMatrix[k][j];
            }
        }
    }

    return pathMatrix;
}