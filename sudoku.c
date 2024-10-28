#include <stdio.h>

void le_matriz(int matriz[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int confere_matriz_maior(int matriz[9][9]) {
    for (int i = 0; i < 9; i++) {
        int linha[10];  
        int coluna[10];
        
        for(int s = 0; s<10; s++){
            linha[s] = 0;
            coluna[s] = 0;
        }

        for (int j = 0; j < 9; j++) {
            int valor_linha = matriz[i][j];
            int valor_coluna = matriz[j][i];

            if (valor_linha >= 1 && valor_linha <= 9 && valor_coluna >= 1 && valor_coluna <= 9) {
                linha[valor_linha]++;
                coluna[valor_coluna]++;
            } else {
                return 0;
            }
            
        }
        
        for(int k = 0; k < 10; k++){
            if(linha[k] > 1 || coluna[k] > 1){
                return 0;
            }
            
        }
    }
    return 1; 
}


int confere_matrizes_menores(int matriz[9][9]) {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int submatriz[10];  
            
            for(int s = 0; s<10; s++){
                submatriz[s] = 0;
                
            }

            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++){
                    submatriz[matriz[k][l]]++;
                }
            }
            
            for(int r=0; r<10; r++){
                if(submatriz[r] > 1){
                    return 0;
                }
            }
        }
    }
    return 1; 
}

int main() {
    int n, matriz[9][9];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        le_matriz(matriz);

        int matriz_maior = confere_matriz_maior(matriz);
        int matriz_menor = confere_matrizes_menores(matriz);

        printf("Instancia %d\n", i + 1);
        if (matriz_maior && matriz_menor) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
        
    }
    
}
