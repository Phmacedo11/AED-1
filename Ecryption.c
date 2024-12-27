#include <stdio.h>
#include <string.h>

void encrypt(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] += 3;
        }
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    for (int i = len / 2; i < len; i++) {
        str[i] -= 1;
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    char str[1001];
    while (n--) {
        fgets(str, 1001, stdin);
        str[strcspn(str, "\n")] = '\0';
        encrypt(str);
        printf("%s\n", str);
    }
    return 0;
}
