/* A generic weighted graph data type */

#include "bool.h"

#define	MAXV		100		/* maximum number of vertices */
#define MAXDEGREE	50		/* maximum outdegree of a vertex */

typedef struct {
	int v;				/* neighboring vertex */
	int weight;			/* edge weight */
} edge;

typedef struct {
	edge edges[MAXV+1][MAXDEGREE];	/* adjacency info */
	int degree[MAXV+1];		/* outdegree of each vertex */
	int nvertices;			/* number of vertices in the graph */
	int nedges;			/* number of edges in the graph */
} graph;

initialize_graph(graph *g){
	int i;				/* counter */
	g -> nvertices = 0;
	g -> nedges = 0;
	for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}

read_graph(graph *g, bool directed){
	int i;				/* counter */
	int m;				/* number of edges */
	int x,y,w;			/* placeholder for edge and weight */
	initialize_graph(g);
	scanf("%d %d\n",&(g->nvertices),&m);
	for (i=1; i<=m; i++) {
		scanf("%d %d %d\n",&x,&y,&w);
		insert_edge(g,x,y,directed,w);
	}
}

insert_edge(graph *g, int x, int y, bool directed, int w){
	if (g->degree[x] > MAXDEGREE)
		printf("Warning: insertion(%d,%d) exceeds degree bound\n",x,y);
	g->edges[x][g->degree[x]].v = y;
	g->edges[x][g->degree[x]].weight = w;
	/*g->edges[x][g->degree[x]].in = FALSE;*/
	g->degree[x] ++;
	if (directed == FALSE)	insert_edge(g,y,x,TRUE,w);
	else g->nedges ++;
}

delete_edge(graph *g, int x, int y, bool directed){
	int i;				/* counter */
	for (i=0; i<g->degree[x]; i++) 
		if (g->edges[x][i].v == y) {
			g->degree[x] --;
			g->edges[x][i] = g->edges[x][g->degree[x]];
			if (directed == FALSE)
				delete_edge(g,y,x,TRUE);
			return;
		}
	printf("Warning: deletion(%d,%d) not found in g.\n",x,y);
}

print_graph(graph *g){
	int i,j;			/* counters */
	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		for (j=0; j<g->degree[i]; j++)
			printf(" %d",g->edges[i][j].v);
		printf("\n");
	}
}

bool processed[MAXV];		/* which vertices have been processed */
bool discovered[MAXV];          /* which vertices have been found */
int parent[MAXV];		/* discovery relation */


initialize_search(graph *g;){
        int i;                          /* counter */
        for (i=1; i<=g->nvertices; i++) {
                processed[i] = FALSE;
                discovered[i] = FALSE;
                parent[i] = -1;
        }
}

dfs(graph *g, int v){
	int i;				/* counter */
	int y;				/* successor vertex */
	discovered[v] = TRUE;
	process_vertex(v);
	for (i=0; i<g->degree[v]; i++) {
		y = g->edges[v][i].v;
		if (discovered[y] == FALSE) {
			parent[y] = v;
			dfs(g,y);
		} else 
			if (processed[y] == FALSE)
				process_edge(v,y);
	}
	processed[v] = TRUE;
}

process_vertex(int v){
	printf(" %d",v);
}

process_edge(int x, int y){
}

find_path(int start, int end, int parents[]){
	if ((start == end) || (end == -1))
		printf("\n%d",start);
	else {
		find_path(start,parents[end],parents);
		printf(" %d",end);
	}
}

connected_components(graph *g){
	int c;				/* component number */
	int i;				/* counter */
	initialize_search(g);
	c = 0;
	for (i=1; i<=g->nvertices; i++)
		if (discovered[i] == FALSE) {
			c = c+1;
			printf("Component %d:",c);
			dfs(g,i);
			printf("\n");
		}
}
