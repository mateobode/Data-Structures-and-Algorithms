#include "utils.h"
#include "queue.h"
#include "queue_node.h"


/**
 * @brief Functie ce aloca dinamic memorie pentru coada,
 *        initializand campurile front si rear
 * 
 * @param queue - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru coada
 */
void createQueue(Queue **queue)
{
    *queue = (Queue*)malloc(sizeof(Queue));
    (*queue) -> front = NULL;
    (*queue) -> rear = NULL;
}

/**
 * @brief Functie ce va fi folosita pentru a adauga un nod in coada queue
 * 
 * * Hint:
 *         * se va folosi functia createQueueNode pentru crearea unui nou nod
 *         * trebuie actualizati poniterii rear si front sau doar front
 *         * a se citi cursul :)
 * 
 * @param queue - coada in care trebuie adaugat un nou nod cu informatia data
 * @param data - datele noului nod
 */
void en(Queue *queue, char *data)
{

    if(queue -> rear == NULL) //daca nu avem niciun nod in coada
        
        queue -> rear = createQueueNode(data);
    
    else if(queue -> front == NULL){ //daca este singurul element din coada
        
        queue -> front = createQueueNode(data);
        queue -> front -> next = queue -> rear; 
    
    }else{
        //daca deja avem noduri
        queue_node *nod = queue -> front;
        queue -> front = createQueueNode(data);
        queue -> front -> next = nod;
    }
}
/**
 * @brief Functie ce scoate din coada urmatorul nod si
 *        returneaza datele stocate in nod.
 * * Hint:
 *        * a se citi cursul :)
 * 
 * @param queue - coada din care va fi scos nodul 
 * @return char* - datele din interiorul nodului
 */
char *de(Queue *queue)
{
    char *node_data;
    node_data = (char*)malloc(strlen(queue -> rear -> data));
    strcpy(node_data, queue -> rear -> data); //stochez datele de la urmatorul nod

    if(queue -> front == NULL){ //daca coada este goala
        
        deleteQueueNode(queue -> rear); 
    
    }else if(queue -> front -> next == queue -> rear){ //daca avem un nod
        
        deleteQueueNode(queue -> rear);
        queue -> rear = queue -> front;
        queue -> front = NULL;

    }else{
        
        queue_node *nod;
        nod = queue -> front;
        
        while(nod -> next != queue -> rear) //daca avem mai multe noduri
            nod = nod -> next;
        
        deleteQueueNode(queue -> rear);
        queue -> rear = nod;       
    }

    return node_data;
}

/**
 * @brief Functie ce va elibera memoria asociata fiecarui nod al cozi
 *  
 *  * Hint:
 *          * se poate folosi functia deleteQueueNode
 * @param queue - coada a carui noduri vor fi sterse
 */
void deleteQueue(Queue *queue){

}

/**
 * @brief Functie ce testeaza pointerii rear si front pentru 
 *        a determina daca coada este goala
 * 
 * @param queue - coada ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyQueue(Queue *queue)
{
    if(isNull(queue) == 1)
        return 0;
}
