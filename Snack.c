#include <stdio.h>
 
int main() {
    
    float v[5] = {4.00, 4.50, 5.00, 2.00, 1.50};
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    if (x <=5){
        printf("Total: R$ %.2f\n", v[x-1]*y);
    }
    else printf("Wrong code"); 
 
    return 0;
}