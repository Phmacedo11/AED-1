#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int BemFormada(char s[]) {
    int t = 0;  
    int len = strlen(s);
    char *p = (char*)malloc(len*sizeof(char));
    
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '(': 
                if(s[i+1] != '\0'){p[t++] = s[i];} 
                else {return 0;}

                break;

            case ')':
                if(t!=0 && p[t-1] == '(') {--t;}
                else {return 0;}

            default:
                break;
        }
    }
    free(p);
    return t == 0;  
}

int main() {

    char s[1001];
    int *res = NULL, count=0;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        
        res = (int*)realloc(res, (count + 1)*sizeof(int));

        s[strcspn(s, "\n")] = '\0';

        res[count++] = BemFormada(s);
    }

    for (int i = 0; i < count; i++) {
        if (res[i] == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    free(res);
    return 0;
}

