#include "utils.h"
#include "stack.h"
#include "stack_node.h"

/**
 * @brief Functie ce aloca dinamic memorie pentru stiva,
 *        initializand campurile head si size
 * 
 * @param stack - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru stiva
 */

void createStack(Stack **stack)
{
    *stack = (Stack*)malloc(sizeof(Stack));
    (*stack)->size = 0;
    (*stack)->head = NULL;
}
/**
 * @brief Functie ce dealoca memoria pentru stiva
 * 
 * @param stack - stiva a carei elemente trebuie sterse
 */
void deleteStack(Stack *stack)
{
    // Nice to have
}

/**
 * @brief Functie ce adauga un nou nod in stiva
 * 
 *  * Hint:
 *          * a se citi cursul :)
 *          * se va modifica pointer-ul head al structurii Stack
 * 
 * @param stack - stiva in care se va adauga un nou nod
 * @param data - informatiile noului nod
 */
void push(Stack *stack, char data)
{
   stack_node *nod = createStackNode(data); //creez un nou stacknode
   
   stack -> head = nod; // in varful stivei stochez valoarea noului nod
   stack -> head -> data = data; 
   stack -> head -> next = nod;
}

/**
 * @brief Functie ce elimina urmatorul nod din stiva
 * 
 *  * Hint:
 *          * a se citi cursul :)
 *          * se va modifica pointer-ul head al structurii Stack
 * 
 * @param stack - stiva din care se va elimina nodul
 * @param data - informatiile noului scos
 */
char pop(Stack *stack)
{
    char val = stack -> head -> data; //in val stochez valoarea varfului stivei (elementului ce va fi scos)
    stack_node *Nod = stack -> head; //in Nod stochez varful stivei

    //elemin urmatorul nod din stiva
    Nod = Nod -> next;
    free(Nod);
    return val;  //returnez valoarea elementului scos
}

/**
 * @brief Functie ce testeaza dimensiune stivei pentru a vedea daca este goala
 * 
 * @param stack - stiva ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyStack(Stack *stack)
{
    if(isNull(stack) == 1)
        return 0;
}