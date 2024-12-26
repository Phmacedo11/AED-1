#include <stdio.h>
#include <math.h>

void count_notes_coin(float n) {
    int parteinteira = (int)n;
    int partedecimal = round((n - parteinteira) * 100);

    int notes[6] = {100, 50, 20, 10, 5, 2};
    int coins[6] = {100, 50, 25, 10, 5, 1};

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        int count = parteinteira / notes[i];
        if (i+1 == 6 && parteinteira < 2){
            printf("%d nota(s) de R$ %d.00\n", count, notes[i]);
            break;
        }
        parteinteira %= notes[i];
        printf("%d nota(s) de R$ %d.00\n", count, notes[i]);
    }

    partedecimal += (parteinteira * 100);

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        int count = partedecimal / coins[i];
        partedecimal %= coins[i];
        printf("%d moeda(s) de R$ %.2f\n", count, coins[i] / 100.0);
    }
}

int main() {
    float n;
    scanf("%f", &n);
    count_notes_coin(n);
}








