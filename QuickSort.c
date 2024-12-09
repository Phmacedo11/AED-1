#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 10000; 

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p;k < r; k++){
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void Quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}


int main(){
    clock_t t; 
    int *vetor, TAM[20];
    
    TAM[0] = 20000;
    for(int i = 1; i<20; i++){
        TAM[i] = TAM[i-1] + 20000;
    }
    
    for(int i = 0; i<20; i++){
        
        vetor = (int*)malloc(TAM[i] * sizeof(int));
        
        srand((unsigned)time(NULL));
    
        
        for(int a = 0; a < TAM[i]; a++)
            vetor[a] = rand() % TAM[i];
    
        
        t = clock();
        Quicksort(0,TAM[i], vetor);
        t = clock() - t;
    
        
        printf("%lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    }
        return 0;
}