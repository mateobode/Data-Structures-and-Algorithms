#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param data - informatia nodului respectiv
 * @param next - adresa urmatorului nod
 * @return node* nou nod creat
 */
node *makeNode(int data, node *next)
{
    node *head;
    head = (node*)malloc(sizeof(node));
    
    if(head == NULL){
        head->data = data;
        head->next = next;
    }
    
    return head;
}



/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return node* 
 */
node *makeList(FILE *file)
{   
    char *filename;
    int file_contents;
    node *head;
    node *new_node;

    file = openFile(filename, "rt");
    
    while(fscanf(file, "%d", &file_contents) != EOF){   
        if(head == NULL){
            head = makeNode(file_contents, head);
            return head;
        }
        else{
            new_node = makeNode(file_contents, new_node);
            new_node->next = head;
            head = new_node;
            return new_node;
         }
    }
    fclose(file);
    return 0;
}


/**
 * @brief Functie ce afiseaza toate elementele unei liste
 *  
 * @param head - capul listei de afisat
 */
void print(node *head)
{
    if(head != NULL){
        printf("%d", head->data);
        print(head->next);
    }
}