#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplify(int *num, int *den) {
    int divisor = gcd(*num, *den);
    *num /= divisor;
    *den /= divisor;
    if (*den < 0) {
        *num = -*num;
        *den = -*den;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int n1, d1, n2, d2, nr, dr;
        char op, slash;
        scanf("%d %c %d %c %d %c %d", &n1, &slash, &d1, &op, &n2, &slash, &d2);
        switch (op) {
            case '+':
                nr = n1 * d2 + n2 * d1;
                dr = d1 * d2;
                break;
            case '-':
                nr = n1 * d2 - n2 * d1;
                dr = d1 * d2;
                break;
            case '*':
                nr = n1 * n2;
                dr = d1 * d2;
                break;
            case '/':
                nr = n1 * d2;
                dr = n2 * d1;
                break;
        }
        printf("%d/%d = ", nr, dr);
        simplify(&nr, &dr);
        printf("%d/%d\n", nr, dr);
    }
    return 0;
}