#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
struct Node {
	int value;
	List next;
};

List append(List l, int x) {
	List new = malloc(sizeof(struct Node));
	new->value = x;
	new->next = l;
	return new;
}

void show(List l) {
	List curr = l;
	while (curr != NULL) {
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int less(int a, int b) {
	return a < b;
}

void swap(List a, List b) {
	int tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

List selectionSort(List ls) {
	List i, j, min;
   for (i = ls; i != NULL; i = i->next) {
      min = i;
      for (j = i->next; j != NULL; j = j->next) {
         if (less(j->value, min->value)) min = j;
      }
      swap(i, min);
   }
}

int main(int argc, char** argv) {
	List l = NULL;
	for (int i = argc - 1; i > 0; i--) l = append(l, atoi(argv[i]));
	show(l);
	selectionSort(l);
	show(l);
}