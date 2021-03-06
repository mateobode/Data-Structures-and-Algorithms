#include "utils.h"

FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Fisierul %s nu a putut fi deschis!", filename);
        printf("Iesire program!");
        exit(EXIT_FAILURE);
    }
    return file;
}

bool isNull(void *argument)
{
    return argument == NULL;
}

bool isNotNull(void *argument) {
    return !isNull(argument);
}

//functie ce am folosit pentru stergerea nodului
void swap(int *l, int *r){
    int aux;
    aux = *l;
    *l = *r;
    *r = aux;
}