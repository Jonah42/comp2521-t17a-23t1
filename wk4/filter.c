#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node {
    int value;
    struct node *next;
} *Node;

typedef struct list {
    Node head;
} *List;

typedef int (*FilterFunc)(int);

void append(List l, int x) {
    Node new = malloc(sizeof(struct node));
    new->value = x;
    new->next = l->head;
    l->head = new;
}

void show(List l) {
    Node curr = l->head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int filterOdds(int x) {
    return x%2 == 0;
}

int filterEvens(int x) {
    return x%2 != 0;
}

Node doListFilter(Node n, FilterFunc fp) {
    if (n == NULL) return NULL;
    if (fp(n->value) == 0) { // delete
        Node next = n->next;
        free(n);
        return doListFilter(next, fp);
    }
    n->next = doListFilter(n->next, fp);
    return n;
}

void listFilter(List l, FilterFunc fp) {
    l->head = doListFilter(l->head, fp);
}


int main(int argc, char** argv) {
    List l = malloc(sizeof(struct list));
    assert(l != NULL);
    l->head = NULL;
    for (int i = argc - 1; i > 0; i--) append(l, atoi(argv[i]));
    show(l);
    listFilter(l, filterEvens);
    show(l);
    return 0;
}