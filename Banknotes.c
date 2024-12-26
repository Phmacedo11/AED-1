#include <stdio.h>
#include <math.h>

void count_notes(int n) {

    int notes[7] = {100, 50, 20, 10, 5, 2, 1};
    

    printf("%d\n", n);
    for (int i = 0; i < 7; i++) {
        int count = n / notes[i];
        n %= notes[i];
        printf("%d nota(s) de R$ %d,00\n", count, notes[i]);
    }

}

int main() {
    int n;
    scanf("%d", &n);
    count_notes(n);
}








