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

typedef int (*ReduceFunc)(int, int);

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

int formNumber(int prev, int curr) {
    return prev * 10 + curr;
}

int doListReduce(Node n, ReduceFunc fp, int init) {
    if (n == NULL) return init;
    int ret = doListReduce(n->next, fp, init);
    return formNumber(ret, n->value);
}

int listReduce(List l, ReduceFunc fp, int init) {
    return doListReduce(l->head, fp, init);
}

int main(int argc, char** argv) {
    List l = malloc(sizeof(struct list));
    l->head = NULL;
    assert(l != NULL);
    for (int i = argc - 1; i > 0; i--) append(l, atoi(argv[i]));
    show(l);
    int ret = listReduce(l, formNumber, 0);
    printf("%d\n", ret);
    return 0;
}