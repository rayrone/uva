/* A generic adjacency list-in-array graph data type. */

#include<stdio.h>

#define	MAXV		100		/* maximum number of vertices */
#define MAXDEGREE	50		/* maximum outdegree of a vertex */
#define BOOL int

typedef struct {
	int edges[MAXV+1][MAXDEGREE];	/* adjacency info */
	int degree[MAXV+1];		/* outdegree of each vertex */
	int nvertices;			/* number of vertices in the graph */
	int nedges;			/* number of edges in the graph */
} graph;

enum { FALSE, TRUE};

void initialize_graph(graph *g){
	int i;				/* counter */
	g -> nvertices = 0;
	g -> nedges = 0;
	for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, BOOL directed){
	if (g->degree[x] > MAXDEGREE)
	    printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);
	g->edges[x][g->degree[x]] = y;
	g->degree[x] ++;
	if (directed == FALSE) insert_edge(g,y,x,TRUE);
	else g->nedges ++;
}

void delete_edge(graph *g, int x, int y, BOOL directed){
	int i;				/* counter */
	for (i=0; i<g->degree[x]; i++) 
		if (g->edges[x][i] == y) {
			g->degree[x] --;
			g->edges[x][i] = g->edges[x][g->degree[x]];
			if (directed == FALSE)
				delete_edge(g,y,x,TRUE);
			return;
		}
	printf("Warning: deletion(%d,%d) not found in g.\n",x,y);
}

void read_graph(graph *g, BOOL directed){
	int i;				/* counter */
	int m;				/* number of edges */
	int x, y;			/* vertices in edge (x,y) */

	initialize_graph(g);
	scanf("%d %d",&(g->nvertices),&m);
	for (i=1; i<=m; i++) {
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

void print_graph(graph *g){
	int i,j;			/* counters */
	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		for (j=0; j<g->degree[i]; j++)
			printf(" %d",g->edges[i][j]);
		printf("\n");
	}
}
