#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod {
    char name[25];
    struct nod *seg;
}node;

void recieve_list(char **list) {
    *list = (char*)malloc(50 * sizeof(char));  

    fgets(*list, 50, stdin);

    int len = strlen(*list);

    if (len > 0 && (*list)[len - 1] == '\n') {
        (*list)[len - 1] = '\0';
    }
}


node *fill_nodes(char *list){

    
    int inicio = 0;
    node *next_node = NULL, *head = NULL, *end = NULL;


    for(int i=0; list[i] != '\0'; i++){

        if(list[i] == ' ' || list[i+1] == '\0'){

            int length = i - inicio;
            if(list[i+1] == '\0'){
                length++;
            }
            
            char *unique_names = (char*)malloc((length+1)*sizeof(char));

            if(unique_names == NULL){
                printf("string's memory allocation error");
                exit(1);
            }

            strncpy(unique_names, list + inicio, length);
            unique_names[length] = '\0';

            next_node= (node*)malloc(sizeof(node));
            if(next_node == NULL){
                printf("node's memory allocation error");
                exit(1);
            }

            strncpy(next_node->name, unique_names, length+1);
            next_node->seg = NULL;
        
            if(head == NULL){
                head = next_node;
            }
            else{
                end->seg = next_node;
            }
            end = next_node;

            inicio = i + 1;
            free(unique_names);
        }
    }   
    return head;

}



node *join(char *s , node *current_node, node *new_node){

    node *p = NULL, *q = current_node, *tail_new = new_node;

    while(tail_new->seg != NULL){
        tail_new = tail_new->seg;
    }

    if(strcmp(s, "nao") == 0){
        while(q != NULL){
            p = q;
            q = q->seg;
        }
        p->seg = new_node;
    }
    else{
        while(q != NULL && strcmp(q->name, s) !=0){
            p = q;
            q = q->seg;
        } 
        
        if(q != NULL){
            if(p == NULL){
                tail_new->seg = current_node; 
                current_node = new_node;
            }
            else{
                p->seg = new_node;
                tail_new->seg = q;
            }
        }
        else{
            p->seg = new_node;
        }

    }

    return current_node;

}



int main(){

    char *current_list = NULL, *new_list = NULL, *join_name = NULL;
    node *current_node, *new_node, *final_node;

    recieve_list(&current_list);
    recieve_list(&new_list);
    recieve_list(&join_name);

    current_node = fill_nodes(current_list);
    new_node = fill_nodes(new_list);
    
    final_node = join(join_name, current_node, new_node);

    for(node *i = final_node; i != NULL; i = i->seg) {
        fputs(i->name, stdout);
        printf(" "); 
    }


    node *temp;
    while (final_node != NULL) {
        temp = final_node;
        final_node = final_node->seg;
        free(temp);
    }

    return 0;
}
