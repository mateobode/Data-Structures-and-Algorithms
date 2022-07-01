#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce elimina elementele cu informatii duplicate
 * Hint:
 *      * parcurgeti lista si modificati nodurile a.i sa elimi-
 *        nati duplicatele
 *      * daca capul listei nu se modifica va trebuii 
 *        sa il returnati
 * 
 * @param list - capul listei ce trebuie sa fie procesata
 * @return node* - returneaza capul listei
 */
node *removeDuplicates(node *list)
{
    node *head = list;
    node *next_node; //un pointer ce o sa stocez ptr de la nodul urmator ce va fi sters

    if(head == NULL)
        return 0;

    //parcurg lista
    while(head->next != NULL){
        //comparam nodul curent cu cel urmator
        if(head->data == head->next->data){
            next_node = head->next->next;
            free(head->next);
            head->next = next_node;
        }
        else{
            head = head->next; //vedem urmatorele noduri daca nu am sters nimic
        } 
    }
    return head;
}
