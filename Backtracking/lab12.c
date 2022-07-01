#include <stdio.h>
#define max 30

int pi[max]; //profitul obiectului respectiv
int gi[max]; //greutatea obiectului respectiv
int N; //nr total de obiecte
int Gmax; //capacitatea maxima a rucsacului
int final_pi = -1; //profitul final
int final_gi; //greutatea finala
int temp[max]; //variabila temporara
int xi[2]; //avem doar 1 din fiecare obiect, deci exista fie 0, fie 1 din fiecare obiect in rucsac

/*
    Functie care citeste datele din fisierul input
 */

void read(FILE* input){
    fscanf(input, "%d", &N);
    fscanf(input, "%d", &Gmax);
    for(int i=0; i<N; i++){
        fscanf(input, "%d", &gi[i]); 
        fscanf(input, "%d", &pi[i]);
    }
}

/*
    Functie care scrie datele rularii in fisierul output
*/

void print(FILE* output){
    int sum=0;
    int i;
    for(i=0; i<N; i++){
        if(xi[i] == 1){
            fprintf(output, "selectez obiectul %d\t", i+1);
            sum += pi[i] * xi[i];
        }
    }
    fprintf(output, "\nMax profit= %d", sum);
}

/*
    Functie care returneaza limita superioara a profitului realizabil 
    cu rucsacul curent astfel incat sa reduca spatiul de cautare.
*/

int calculate_bound(int curent_pi, int curent_gi, int n){
    int i, j;
    int upper_bound = curent_pi;
    j = curent_gi;

    for(i=n; i<=N; i++){
        j = j + gi[i];
        if(j<Gmax)
            upper_bound = upper_bound + pi[i];
        else
            return (upper_bound+(1-(j-Gmax)/gi[i])*pi[i]);
    }
    return upper_bound;
}

/*
    Functie care implementeaza algoritmul backtracking
*/

void backtrack(int n, int curent_pi, int curent_gi){
    int i,j;

    if(curent_gi + gi[n] <= Gmax){
        temp[n] = 1;
        if(n < N){
            backtrack(n+1 ,curent_pi + pi[n], curent_gi + gi[n]);
        }
        if(((curent_pi+pi[n]) > final_pi) && (n==N)){
            final_pi = curent_pi + pi[n];
            final_gi = curent_gi + gi[n];
            for(j=0; j<=n; j++){
                xi[j] = temp[j]; //setez xi = 1
            }
        }
    }

    if(calculate_bound(curent_pi, curent_gi, n) >= final_pi){
        temp[n] = 0;

        if(n <= N){
            backtrack(n+1, curent_pi, curent_gi);
        }
        if((curent_pi>final_pi) && (n==N)){
            final_pi = curent_pi;
            final_gi = curent_gi;
            for(j=0; j<=n; j++){
                xi[j] = temp[j]; //setez xi = 0
            }
        }
    }
}


void main(){
    FILE *input = fopen("input.txt", "r+");
    FILE *output = fopen("output.txt", "wb");
    read(input);
    backtrack(0,0,0);
    print(output);    
}
