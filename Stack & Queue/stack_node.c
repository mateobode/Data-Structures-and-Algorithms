#include "stack_node.h"

/**
 * @brief Functie ce creaza un nod pentru stiva
 * 
 * 
 * @param data - informatiile noului nod
 * @return stack_node* - pointer-ul noului 
 */
stack_node *createStackNode(char data)
{
    stack_node *newNode;
    newNode = (stack_node*)malloc(sizeof(stack_node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}