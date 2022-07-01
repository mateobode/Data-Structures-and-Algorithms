#include "merge.h"
#include "quick.h"
#include "utils.h"

//----- MergeSort -----

/**
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param middle - pozitia din mijloc
 * @param right - pozitia finala
 */
void merge(int *arr, int left, int middle, int right)
{
    int x, y, i, j;
    int k = left;
    y = right - middle;
    x = middle - left + 1;

    int arr_left[x], arr_right[y];

    for(i=0; i<x; i++)
        arr_left[i] = arr[left + i];
    for(j=0; j<y; j++)
        arr_right[j] = arr[middle + 1 + j];

    i = j = 0;

    while(i<x && j<y){
        if(arr_left[i] < arr_right[j]){
            arr[k] = arr_left[i];
            i++;
        }
        else{
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }
    while(i<x){
        arr[k] = arr_left[i];
        i++;
        k++;
    }
    while(j<y){
        arr[k] = arr_right[j];
        j++;
        k++;
    }
}

/**
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param right - pozitia finala
 */
void mergesort(int *arr, int left, int right)
{
    int middle = (left + right) / 2;

    if(left < right){
        mergesort(arr, left, right);
        mergesort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}

//----- Quick Sort -----

/**
 * @param x - primul element
 * @param y - al doilea element
 */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Consideram pivotul a fi ultimul element din vector
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int index = (low - 1);
    int i;

    for(i=low; i<=high-1; i++){
        if(arr[i] < pivot){
            index++;
            swap(&arr[index], &arr[i]);
        }
    }

    swap(&arr[index+1], &arr[high]);
    return(index+1);
}

/**
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
void quicksort(int *arr, int low, int high)
{
    int q;
    if(low < high){
        q = partition(arr, low, high);
        quicksort(arr, low, q-1);
        quicksort(arr, q+1, high);
    }
}

//----- Analiza functiilor -----

/**
 * //TODO: Care dintre metodele anterior implementate reprezinta metode de sortare stabile
 * si care reprezinta metode de sortare instabile? Argumentati.
        Dintre metodele de mai sus cea MergeSort este stabila pentru ca
        mentine ordinea relativa a inregistrarilor cu chei egale, iar QuickSort
        nu este stabila pentru ca noi facem interschimbare a elementelor (swap)
        in functie de pozitia pivotului fara a lua in considerare pozitia initiala.
        Oricum si QuickSort se poate face sa fie stabila.
 */