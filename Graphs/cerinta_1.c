#include "utils.h"


/**
 * TODO:   O functie ce transforma un graf reprezentat de o matrice de adiacenta 
 * intr-unul reprezentat cu ajutorul listelor de adiacenta
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - Graful in reprezentarea liste de adiacenta
 */
graph_list* matrixToList(graph_matrix* graph) {
    int i, j;
    
    graph_list* adjList = (graph_list*)malloc(sizeof(graph_list));
    
    if(adjList == NULL){
        return NULL;
    }

    adjList -> E = graph -> E;
    adjList -> V = graph -> V;

    adjList -> listHeads = (node**)calloc(graph->V, sizeof(node*));

    for(i=0; i<graph->V; i++){
        for(j=0; j<graph->V; j++){
            if(graph->matrix[i][j] == 1){
                adjList -> listHeads[i] = push_values(adjList->listHeads[i], j);
            }
        }
    }

    return adjList;
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_matrix(graph_matrix** graph) {
    int i;
    
    for(i=0; i<(*graph)->V; i++){
        free((*graph) -> matrix[i]);
    }
    
    free((*graph) -> matrix);
    free((*graph));
    *graph = NULL;
}


node* push_values(node* root, int val) {
    if(root == NULL){
        node *temp = (node*)malloc(sizeof(node));
        isNotNull((node*)temp);
        temp -> next = NULL;
        temp -> vertexNr = val;
        return temp;
    }

    root -> next = push_values(root->next, val);
    return root;
}


void print_graph_list(graph_list* graph) {
    int i;
    for(i=0; i<graph->V; i++){
        while(graph->listHeads[i] != NULL){
            printf("%d ", graph->listHeads[i]->vertexNr);
            graph -> listHeads[i] = graph -> listHeads[i] -> next; 
        }
        printf("\n");
    }
}



