#include "utils.h"

/**
 * TODO: Implementati o functie de cautare a unui nod in
 * 	functie de valoarea din acesta
 * @note   
 * @param  root: Radacina arborelui
 * @param  data: Valoarea de cautat
 * @retval Nodul cautat, daca nu este gasit se returneaza NULL
 */
BST* findNode(BST* root, int data)
{
    if(root -> data == data)
        return root;
    if(data >= root->data)
        return findNode(root->right, data);
    
    return findNode(root->left, data);
}
/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea maxima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea maxima din arbore/subarbore
 */
BST* findMax(BST* root)
{
    BST* max = root;

    while(max->right != NULL)
        max = max -> right;
    
    return max;
}

/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea minima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea minima din arbore/subarbore
 */
BST* findMin(BST* root)
{
    BST* min = root;

    while(min->left != NULL)
        min = min -> left;
    
    return min;
}

/**
 * TODO: Implementati o functie ce returneaza succesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui succesor trebuie gasit
 * @retval Succesorul nodului root
 */
BST* findSuccesor(BST* root)
{
	if(root->right != NULL)
        return findMin(root->right);

    BST* succesor = root -> parent;
    while(succesor != NULL && root == succesor->right){
        root = succesor;
        succesor = succesor -> parent;
    }

    return succesor;
}

/**
 * TODO: Implementati o functie ce returneaza predecesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui predecesor trebuie gasit
 * @retval Predecesorul nodului root
 */
BST* findPredecessor(BST* root)
{
	if(root->left != NULL)
        return findMax(root->left);

    BST *predecessor = root -> parent;
    while(predecessor != NULL && root == predecessor->left){
        root = predecessor;
        predecessor = predecessor -> parent;
    }

    return predecessor;
}
