#include "queue_node.h"
#include "utils.h"

/**
 * @brief Functie ce copiaza sirul de caractere data si atribuie
 *        adresa de memorie a noului sir campului data al noului
 *        nod creat
 * 
 * @param data 
 * @return queue_node* 
 */
queue_node *createQueueNode(char *data)
{
    queue_node *newNode;
    newNode = (queue_node*)malloc(sizeof(queue_node));
    newNode -> data = (char*)malloc(strlen(data) * sizeof(char));
    strcpy(newNode -> data, data);
    newNode -> next = NULL;
    return newNode;
}
/**
 * @brief Functie ce face eliberarea de memorie pentru nodul oldNode
 * 
 * * Hint:
 *         * doar campul data necesita eliberarea memoriei, acesta fiind alocat dinamic
 * 
 * @param oldNode - nodul a carui date trebuie sterse
 */
void deleteQueueNode(queue_node *oldNode){
    if(oldNode -> data != NULL)
        free(oldNode -> data);
}