#include "Graph.h"
#include <stdlib.h>
#include "list.h"

void dfs(Graph g, int v, int * visited) {
	visited[v] = 1;
	// for all adjacent nodes
	for (int w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && visited[w] == 0) {
			dfs(g, w, visited);
		}
	}
}

List reachable(Graph g, Vertex src) {
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	dfs(g, src, visited);
	// Check the visited
	List l = newList();
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (visited[i] == 1) listAppend(l, i);
	}
	free(visited);
	return l;
}

int main(void) {
	Graph g = GraphRead();
	printf("Reachable nodes: \n");
	List l = reachable(g, 0);
	printListSet(l);
	GraphFree(g);
	freeList(l);
	return 0;
}