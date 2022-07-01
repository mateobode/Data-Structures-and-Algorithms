#include "heap.h"

/**
 * TODO: Sortati eficient un vector k-sortat folosind un heap.
 * HINT: Se poate utiliza un heap de dimensiune mai mica decat
 * numarul de elemente din buffer
 * @param  *buffer: - vectorul k sortat
 * @param  dimensiune: numarul de elemente
 * @param  k: indicele de sortare a vectorului k-sortat
 * @retval - vectorul sortat
 */
int *kSortedArray(int *buffer, int dimensiune, int k)
{
    Heap *h = create(k+1);
    int *arr = (int*)malloc(dimensiune * sizeof(int));
    int i, j=0;

    for(i=0; i<k+1; i++) insert(h, buffer[i]);    
    
    for(i=k+1; i<dimensiune; i++){
        arr[j++] = h->vec[0];
        deleteNode(h, 0);
        insert(h, buffer[i]);
    }

    heapsort(h, h->vec, h->size);
    for(i=h->size-1; i>=0; i--) arr[j++] = h->vec[i];

    return arr;
}   
