#include "graph.h"
#include "heap.h"

/**
 * TODO:   Implementati o functie care citeste dintr-un fisier de intrare
 * nr-ul de varfuri, muchii, iar pe urmatoarele linii
 * nod u, nod v si distanta[u][v], pentru a putea reprezenta ulterior matricea de adiacenta
 * @param  input: fisierul de intrare
 * @note   -Atentie! Nu redeschideti fisierul de intrare
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
Graph* createGraph(FILE *input){
    
    int i, u, v, distanta;

    Graph *g = (Graph*)malloc(sizeof(Graph));
    isNull((Graph*)g);   

    fscanf(input, "%d", &g -> V);
    fscanf(input, "%d", &g -> E);

    g -> mat = (int**)malloc(g -> V * sizeof(int*));

    for(i=0; i<g->V; i++){
        g -> mat[i] = (int*)calloc(g -> V, sizeof(int));
    }

    for(i=0; i<g->E; i++){
            fscanf(input, "%d %d %d", &u, &v, &distanta);
            g -> mat[u][v] = distanta;
            g -> mat[v][u] = distanta;
    }

    return g;
}
/**
 * TODO: Implementati functia de afisare a matricei de adiacenta
 * @param  g: graful creat anterior
 * @note : Nice to have
 * @retval - None
 */
void printMat(Graph *g){
    FILE *input;
    int i, j;
    for(i=0; i<g->V; i++){
        for(j=0; j<g->V; j++)
            fprintf(input, "%d ", g->mat[i][j]);
        fprintf(input, "\n");
    }
}