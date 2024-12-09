#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 10000; 

void Intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i-p];
    free (w);
}

void Mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Intercala (p, q, r, v);
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
        Mergesort(0,TAM[i], vetor);
        t = clock() - t;
    
        
        printf("%lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    }
        return 0;
}