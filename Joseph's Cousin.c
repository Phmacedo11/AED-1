#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void generate_primes(int *primes, int max) {
    int count = 0, current = 2;
    while (count < max) {
        if (is_prime(current)) {
            primes[count++] = current;
        }
        current++;
    }
}

int josephus_cousin(int n, int *primes) {
    int *circle = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) circle[i] = i + 1;
    int current_size = n, pos = 0, prime_index = 0;
    while (current_size > 1) {
        pos = (pos + primes[prime_index++] - 1) % current_size;
        for (int i = pos; i < current_size - 1; i++) {
            circle[i] = circle[i + 1];
        }
        current_size--;
    }
    int survivor = circle[0];
    free(circle);
    return survivor;
}

int main() {
    int n;
    int primes[3500];
    generate_primes(primes, 3500);
    while (scanf("%d", &n), n != 0) {
        printf("%d\n", josephus_cousin(n, primes));
    }
    return 0;
}
