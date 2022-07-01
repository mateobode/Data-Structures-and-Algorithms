#include "heap.h"

/**
 * TODO: Implementati functia de creare MinHeap avand o capacitate data
 * @param  capacitate: capacitatea heap-ului
 * @retval - heap-ul creat
 */
MinHeap* create(int capacitate) {
	/*MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    isNotNull((MinHeap*)h);

    h -> size = 0;
    h -> capacity = capacitate;
    
    h -> poz = (int*)malloc(capacitate * sizeof(int));
    isNotNull((MinHeap*)h->poz);
    
	h -> arr = (HeapNode**)malloc(capacitate * sizeof(HeapNode*));
    isNotNull((MinHeap*)h->arr);
    return h;
	*/
}

/**
 * TODO: Implementati functia de creare HeapNode 
 * @param  v:  varful care trebuie adaugat
 * @param dist: distanta rezultata in urma implementarii algoritmului Dijkstra
 * @retval - HeapNode-ul creat
 */
HeapNode *createHeapNode(int v, int dist) {
	/*HeapNode* newNode = (HeapNode*)malloc(sizeof(HeapNode));

	newNode -> v = v;
	newNode ->distanta = dist;

	return newNode;*/
}

/**
 * TODO: Implementati functia de returnare a index-ului
 * parintelui unui nod din MinHeap
 * @param  heap: MinHeap-ul
 * @param  i: index-ul copilului
 * @retval - parintele copilului i
 */

int parent(MinHeap *heap, int i) {
/*	if(i > heap->size-1 || i <= 0)
        return -1;
    return(i-1)/2;*/
}
/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului stang al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din stanga al parintelui i
 */

int leftChild(MinHeap *heap, int i) {
	/*int poz = 2*i+1;
    if(poz > heap->size-1 || i<0)
        return -1;
    return poz;*/
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului drept al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din dreapta al parintelui i
 */
int rightChild(MinHeap *heap, int i) {
/*	int poz = 2*i+2;
    if(poz > heap->size-1 || i<0)
        return -1;
    return poz;*/
}

/**
 * TODO: Implementati functia de returnare a radacinii
 * unui heap   
 * @param  heap: MinHeap-ul
 * @retval - HeapNode-ul in care este stocata radacina
 */
HeapNode* returnRoot(MinHeap *heap) {
	//return heap->arr[0];
}

/**
 * TODO: Implementati functia heapify
 * @param  heap: MinHeap-ul
 * @param  i: pozitia de pe care se doreste
 * @retval None
 */
void heapify(MinHeap *heap, int i) {
	/*while(1){
        int l, r, min=i, aux;
        l = leftChild(heap, i);
        r = rightChild(heap, i);
        
        if(r==-1 && l==-1) return;
        if(l!=-1 && heap->poz[l] < heap->poz[min]) min = l;
        if(r!=-1 && heap->poz[r] < heap->poz[min]) min = r;

        if(min != i){
            aux = heap->poz[i];
            heap->poz[i] = heap->poz[min];
            heap->poz[min] = aux;
            heapify(heap, min);
        }
        else return;
    }*/
}
/**
 * TODO: Implementati functia de redimensionare a MinHeap-ului  
 * @param  heap: MinHeap-ul
 * @retval None
 */
void resize(MinHeap *heap) {
	/*heap->capacity++;
	int *v = (int*)realloc(heap->poz, heap->capacity * sizeof(int));
    isNotNull((MinHeap*)heap);
    heap->poz = v;
	*/
}
/**
 * TODO: Implementati functia de inserare a unui nod in heap
 * @param  heap: MinHeap-ul
 * @param  x: HeapNode-ul care urmeaza a fi inserat
 * @retval None
 */
 
void insert(MinHeap *heap, HeapNode *x){
	/*int i;
	if(heap->size == heap->capacity) resize(heap);
	i = heap->size;
	heap->size++;

	while(i>0 && x<heap->poz[(i-1)/2]){
		heap->poz[i] = heap->poz[(i-1)/2];
		i = (i-1)/2;
	}
	heap->poz[i] = heap->x[i];*/
}




/**
 * TODO: Implementati functia stergere a unui heap
 * @param  h: MinHeap-ul
 * @retval None
 */
void deleteMinHeap(MinHeap **heap){
/*	if(heap == NULL) return;
    if((*heap)->poz != NULL)
        free((*heap)->poz);
    free(*heap);*/
}
/**
 * TODO: Implementati functia de afisare a unui heap
 * @param  heap: MinHeap-ul
 * @note : se va afisa si pozitia HeapNode-urilor, pe langa componentele HeapNode-ului
 * @retval None
 */
void printHeap(MinHeap *heap){
/*	int i;
    for(i=0; i<heap->size; i++)
        printf("%d", heap->poz[i]);*/
}
/**
 * TODO: Implementati functia de stergere a radacinii
 * @param  heap: MinHeap-ul
 * @retval HeapNode-ul care s-a sters, fosta radacina
 */
HeapNode* deleteNode(MinHeap *heap){
	/*if(heap == NULL) return;
    if((*heap)->arr != NULL)
        free((*heap)->arr);
    free(*heap);
	*/

	//return NULL;
}
