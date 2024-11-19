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

    char *s;
    int n, *res;
    
    scanf("%d", &n);
    getchar();
    
    res = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){    
        s = (char*)malloc(1000*sizeof(char));
        
        fgets(s, 1000, stdin);
        
        res[i] = BemFormada(s);
        
        free(s);
        
    }
    
    for(int j=0; j<n; j++){
        if(res[j] == 1)
        printf("correct\n");
        else
        printf("incorrect\n");
    }
    
    free(res);
    printf("\n");
    return 0;
}


