#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int number;
    struct cel *next;
}Node;

Node *fill_list(int n){

    Node *head = NULL, *tail = NULL, *new_node = NULL;

    for(int i=0; i<n; i++){
        int value;
        scanf("%d", &value);
        
        new_node = (Node*)malloc(sizeof(Node));

        new_node->number = value;
        new_node->next = NULL;

        if(head == NULL){
            head = new_node;
        }
        else{
            tail->next = new_node;
        }

        tail = new_node;

    }

    return head;

}

Node *remove_from_list(int *vet, int n, Node *line){

    Node *p = NULL, *q = NULL;

        for(int i=0; i<n; i++){
            p = NULL;
            q = line;
            while(q!= NULL && q->number != vet[i]){
                p = q;
                q = q->next;
            }
            if (q != NULL) {
                if(p == NULL){
                    line = q->next ;
                }
                else{
                     p->next = q->next;
                }
                
                free (q);
            }
            
        }    
    return line;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->number);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
}

int main(){

    int n0, n1, *second_line = NULL;
    Node *line, *fixed_line;

    scanf("%d", &n0);

    line = fill_list(n0);
    
    scanf("%d", &n1);
    second_line = (int*)malloc(n1*sizeof(int));

    for(int i=0; i<n1; i++){
        scanf("%d", &second_line[i]);
    }

    fixed_line = remove_from_list(second_line, n1, line);

    print_list(fixed_line);

    free(second_line);

    printf("\n");
    return 0;
}














