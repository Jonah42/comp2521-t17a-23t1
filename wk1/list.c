#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void listDelete(struct list *l, int value) {
    if (l->head == NULL) {
        return;
    } else if (l->head->value == value) {
        struct node * deleteMe = l->head;
        l->head = l->head->next;
        free(deleteMe);
    } else {
        for (struct node * curr = l->head; curr != NULL; curr = curr->next) {
            if (curr->next->value == value) {
                struct node * deleteMe = curr->next;
                curr->next = curr->next->next;
                free(deleteMe);
                break;
            }
        }
    }
}

int main(void) {
    struct list * l = malloc(sizeof(struct list));
    l->head = malloc(sizeof(struct node));
    l->head->value = 1;
    l->head->next = NULL;
    listDelete(l, 3);
    printf("done!\n");
    return 0;
}