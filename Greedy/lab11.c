#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *pi;
    int *gi;
    int N;
}Rucsac;

Rucsac* read(FILE *input){
    Rucsac *ruc = malloc(sizeof(Rucsac));
    
    fscanf(input, "%d", &ruc -> N);
    ruc -> pi = malloc(ruc -> N * sizeof(int));
    ruc -> gi = malloc(ruc -> N * sizeof(int));

    for(int i=0; i<ruc->N; i++)
        fscanf(input, "%d %d" , &ruc -> pi[i], &ruc -> gi[i]);
    return ruc;
}

void sort(Rucsac *ruc, int l, int m, int r){
    int x = m - l + 1;
    int y = r - m;

    int a[x][2];
    int b[y][2];

    int i, j, k;

    for(i=0; i<x; i++){
        a[i][0] = ruc->pi[l+1];
        a[i][1] = ruc->gi[l+1];
    }

    for(j=0; j<y; j++){
        b[j][0] = ruc->pi[m+1+j];
        b[j][1] = ruc->gi[m+1+j];
    }

    i=j=0;
    k=l;

    while(i<x && j<y){
        if((float)a[i][0] / a[i][1] > (float)b[j][0] / b[j][1]){
            ruc->pi[k++] = a[i++][0];
            ruc->pi[k-1] = a[i-1][1];
        }
        else{
            ruc->pi[k++] = b[i++][0];
            ruc->pi[k-1] = b[i-1][1];
        }
    }

    while(i<x){
        ruc->pi[k++] = a[i++][0];
        ruc->pi[k-1] = a[i-1][1];
    }

    while(j<y){
        ruc->pi[k++] = b[i++][0];
        ruc->pi[k-1] = b[i-1][1];
    }
}

void mergesort(Rucsac *ruc, int l, int r){
    int m;
    if(l < r){
        m = (l+r)/2;
        mergesort(ruc, l, m);
        mergesort(ruc, m+1, r);
        sort(ruc, l, m, r);
    }
}

void print(Rucsac *ruc){
    for(int i=0; i<ruc->N; i++)
        printf("(%d %d) %f\n", ruc->pi[i], ruc->gi[i], (float)ruc->pi[i]/ruc->gi[i]);
}

void greedy(Rucsac *ruc, int Gmax){
    int i=0;
    float profit=0;

    while(Gmax>0 && i<ruc->N){
        if(ruc->gi[i] > Gmax){
            profit += (float)ruc->pi[i] * ((float)Gmax) / ruc->gi[i++];
            Gmax = 0;
        }
        else{
            Gmax -= ruc->gi[i];
            profit += ruc->pi[i++];
        }
    }

    printf("PROFIT = %f\n", profit);
}

int main(){
    int Gmax;
    int N;
    FILE *input = fopen("input", "rt");
    Rucsac *ruc = read(input);
/*
    printf("Enter Gmax = ", Gmax);
    scanf("%d", &Gmax);
    printf("Enter object number = ", N);
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        scanf("%d", &ruc->pi[i]);
        scanf("%d", &ruc->gi[i]);
    }
*/
    mergesort(ruc, 0, -1+ruc->N);
    print(ruc);
    greedy(ruc, 1000);
    return 0;
}