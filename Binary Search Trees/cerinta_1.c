#include "utils.h"

/**
 * TODO: Implementati o functie ce creaza un arbore balansat din datele
 * 	din fisierul f. Arborele nu trebuie sa respecte alta proprietate decat
 *  cea mentionala anterior 
 * @note   
 * @param  N: Numarul de noduri ale arborelui
 * @param  *f: Fisierul din care sunt citite datele de intrare 
 * @retval	Nodul radacina al arborelui creat 
 */
BST* createBalanced(int N, FILE *f) 
{
    int v;

    if(N>0){
        while(fscanf(f, "%d ", &v) != EOF){
            BST *root = (BST*)malloc(sizeof(BST));
            isNotNull((BST*)root);
            *root = (BST){v, createBalanced(N/2, f), createBalanced(N-1-N/2, f), NULL};
            
            if(isNotNull(root->left))
                root -> left -> parent = root;

            if(isNotNull(root->right))
                root -> right -> parent = root;
            
            return root;
        }
    }else 
    return NULL;
    exit(1); //am pus ca mereu imi da warning: control reaches end of non-void function [-Wreturn-type]
}


/**
 * TODO:   Implementati o functie ce testeaza daca un arbore binar este
 * 	un arbore binar de cautare.
 * @note   
 * @param  root: Radacina arborelui
 * @param  max_value: Valoarea maxima intalnita pana la nodul curent
 * @param  min_value: Valoarea minima intalnita pana la nodul curent
 * @retval - true daca arborele este un BST, false in caz contrar
 */
bool checkBST(BST* root, int max_value, int min_value)
{
    if(root == NULL)
        return 1;
    if(root->data < min_value || root->data > max_value)
        return 0;
    
    return checkBST(root->left, root->data, min_value) && checkBST(root->right, max_value, root->data);
}

/**
 * TODO:  Implementati o functie ce aloca memorie pentru un nod 
 * 	si salveaza datele in acesta
 * @note   
 * @param  data: Datele ce trebuie stocate in nod
 * @retval Nodul creat
 */

BST* createBSTNode(int data)
{
	BST *node =(BST*)malloc(sizeof(BST));
    isNotNull((BST*)node);
    node -> left = NULL;
    node -> right = NULL;
    node -> parent = NULL;
    node -> data = data;
    return node;
}
/**
 * TODO: Implementati o functie ce insereaza un nod nou intr-un BST cu
 * 	pastrarea proprietatiilor acestui tip de arbore binar
 * @note   
 * @param  root: Nodul radacina
 * @param  data: Valoarea ce trebuie inserata in arbore
 * @retval Radacina arborelui modificat anterior
 */
BST* insertInBST(BST* root, int data)
{
    if(root == NULL){
        root = createBSTNode(data);
    }

    if(data < root->data){
        if(root->left == NULL){
            root -> left = createBSTNode(data);
            root -> left -> parent = root;
        }
        else{
            insertInBST(root->left, data);
        }
    }
    else{
        if(root->right == NULL){
            root -> right = createBSTNode(data);
            root -> right -> parent = root;
        }
        else{
            insertInBST(root->right, data);
        }
    }

    return root;
}