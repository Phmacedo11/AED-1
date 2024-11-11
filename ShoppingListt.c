#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod {
    char name[20];
    struct nod *seg;
} node;

void receive_list(char **list) {
    *list = (char *)malloc(1000 * sizeof(char));
    fgets(*list, 1000, stdin);

    int len = strlen(*list);
    if (len > 0 && (*list)[len - 1] == '\n') {
        (*list)[len - 1] = '\0';
    }
}

node *get_list(char *list) {
    int inicio = 0;
    node *head = NULL, *tail = NULL;

    for (int i = 0; list[i] != '\0'; i++) {
        if (list[i] == ' ' || list[i + 1] == '\0') {
            int length = i - inicio;
            if (list[i + 1] == '\0') {
                length++;
            }

            char *unique_name = (char *)malloc((length + 1) * sizeof(char));
            strncpy(unique_name, list + inicio, length);
            unique_name[length] = '\0';

            node *next_node = (node *)malloc(sizeof(node));
            strncpy(next_node->name, unique_name, length + 1);
            next_node->seg = NULL;
            free(unique_name);

            if (head == NULL) {
                head = next_node;
            } else {
                tail->seg = next_node;
            }
            tail = next_node;

            inicio = i + 1;
        }
    }
    return head;
}

node *fix_list(node *list) {
    node *i = list;
    while (i != NULL) {
        node *j = i;
        while (j->seg != NULL) {
            if (strcmp(i->name, j->seg->name) == 0) {
                node *dup_node = j->seg;
                j->seg = j->seg->seg;  
                free(dup_node);        
            } else {
                j = j->seg;
            }
        }
        i = i->seg;
    }
    return list;
}

node *order_list(node *list) {
    if (list == NULL || list->seg == NULL) return list;

    node *i, *j;
    char temp[20];

    for (i = list; i != NULL; i = i->seg) {
        for (j = i->seg; j != NULL; j = j->seg) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
        }
    }
    return list;
}

int main() {
    int n; 
    scanf("%d", &n);
    getchar();

    for (int test = 0; test < n; test++) {
        char *list_1 = NULL;
        node *node_1;

        receive_list(&list_1);

        node_1 = get_list(list_1);

        node_1 = fix_list(node_1);

        node_1 = order_list(node_1);

        for (node *i = node_1; i != NULL; i = i->seg) {
            printf("%s", i->name);
            if (i->seg != NULL) printf(" ");  
        }
        printf("\n");

        free(list_1);

        node *temp;
        while (node_1 != NULL) {
            temp = node_1;
            node_1 = node_1->seg;
            free(temp);
        }
    }

    printf("\n");
    return 0;
}

