#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertSort(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
    x = v[j];
    for (i = j-1; i >= 0 && v[i] > x; i--)
    v[i+1] = v[i];
    v[i+1] = x;
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
        InsertSort(TAM[i], vetor);
        t = clock() - t;
    
        
        printf("%2.lf \n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    }
        return 0;
}