#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

List createNode(int data) {
	List newNode = malloc(sizeof(*newNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

List addNode(List l, int data) {
	List newNode = createNode(data);
	newNode->next = l;
	// l = newNode;
	return newNode;
}

int listLength(List l) {
	if (l == NULL)
		return 0;
	return 1 + listLength(l->next);
}

int listCountOdds(List l) {
	// Base case
	if (l == NULL) {
		return 0;
	}
	return l->data%2 + listCountOdds(l->next);
}

bool listIsSorted(List l) {
	if (l->next == NULL) {
		return true;
	}
	return (l->data <= l->next->data) && listIsSorted(l->next);
}

int main(void) {
	List l = NULL;
	l = addNode(l, 4);
	l = addNode(l, 5);
	l = addNode(l, 6);
	l = addNode(l, 27);
	printf("Length is %d\n", listLength(l));
	printf("Odds is %d\n", listCountOdds(l));
	printf("Sorted is %d\n", listIsSorted(l));
	return 0;
}