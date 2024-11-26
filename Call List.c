#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    char names[n][21];

   
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char *temp = (char*)malloc(21*sizeof(char));
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);

                free(temp);
            }
            
        }
    }

    printf("%s\n", names[k - 1]);
    printf("\n");
    return 0;
}
