// Adjacency matrix

struct graph {
	int nV;
	int ** matrix;
}

typedef struct graph * Graph;

Graph GraphNew(int nV) {
	Graph g = malloc(sizeof(struct graph));
	assert(g != NULL);
	g->nV = nV;
	g->matrix = malloc(nV*sizeof(int*));
	for (int i = 0; i < nV; i++) {
		g->matrix[i] = malloc(nV*sizeof(int));
	}
	return g;

}

g->matrix[i][j]

void GraphFree(Graph g) {
	for (int i = 0; i < g->nV; i++)
		free(g->matrix[i]);
	free(g->matrix);
	free(g);
}

int main(void) {
}