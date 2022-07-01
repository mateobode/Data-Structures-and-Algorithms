#include "list.h"
#include "utils.h"



/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param number - numarul pe care il are copilul
 * @param name - numele copilului
 * @param next  - adresa urmatorului nod
 * @return childNode* - nou nod creat
 */
childNode *makeChildNode(int number, const char *name, childNode *next)
{
    childNode *node;
    node = (childNode*)malloc(sizeof(childNode));
    if(node == NULL){
        fprintf(stderr, "erroare la alocare de memorie");
        exit(1);
    }
    node->name = (char*)malloc((strlen(name)+1) * sizeof(char));
    if(node->name == NULL){
        fprintf(stderr, "erroare la alocare de memorie");
        exit(1);
    }
    strcpy(node->name, name);
    node->number = number;
    node->next = next;
    return node;
}

/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeChildNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return childNode* 
 */
childNode *makeCircularList(FILE *file)
{
    char name[10];
    int number;
    char *filename;
    
    childNode *head;
    childNode *new_node;

    file = openFile(filename, "rt");

    head = makeChildNode(number, name, NULL);
    new_node = head;

    while(fscanf(file, "%d %s", &number, name) != EOF){
        head = makeChildNode(number, name, head);
    }

    new_node->next = head;
    return head;
}


/**
 * @brief Functie ce 
 * 
 * @param head - capul listei ce reprezinta cercul de copii
 * @param p - pasul ce va fi luat pentru eliminarea copiilor
 * @return childNode* 
 */
childNode *playJosephGame(childNode *head, int p)
{
   //nu am inteles bine cum trebuie sa implementez :/
}