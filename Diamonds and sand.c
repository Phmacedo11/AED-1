#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_string(char *s){
     fgets(s, 1001, stdin);
        
        int len = strlen(s);

        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
        }
}


int count_diamonds(char*s){
    int t = 0, count = 0;
    int len = strlen(s);
    char *p = (char*)malloc(len*sizeof(char));

    for(int i = 0; s[i]!='\0'; i++){
        switch(s[i]){
            case '<':
                if(s[i+1] != '\0'){
                   p[t++] = s[i]; 
                         
                }
                break;
            
            case '>':
                if(t>0 && p[t-1]=='<'){
                   --t;
                   count++;
                   
                }
                break;

            default:
                break;

        }

    }
    free(p);
    return count;
}



int main(){

    int n;
    scanf("%d", &n);
    getchar();

    int *res = (int*)malloc(n*sizeof(int));

    for(int i = 0; i<n; i++){

        char *string = (char*)malloc(1001*sizeof(char));
        read_string(string);
        res[i] = count_diamonds(string);

    }

    for (int j=0; j<n; j++){
        printf("%d\n", res[j]);
    }

    free(res);
    return 0;

}