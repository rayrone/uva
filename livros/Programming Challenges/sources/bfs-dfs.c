/*	A generic implementation of graph traversal: breadth-first
	and depth-first search
*/

#include "bool.h"
#include "graph.h"
#include "queue.h"

bool processed[MAXV];	/* which vertices have been processed */
bool discovered[MAXV];  /* which vertices have been found */
int parent[MAXV];	/* discovery relation */

bool finished = FALSE;	/* if true, cut off search immediately */

initialize_search(graph *g){
        int i;                          /* counter */
        for (i=1; i<=g->nvertices; i++) {
                processed[i] = discovered[i] = FALSE;
                parent[i] = -1;
        }
}

bfs(graph *g, int start){
	queue q;			/* queue of vertices to visit */
	int v;				/* current vertex */
	int i;				/* counter */
	init_queue(&q);
	enqueue(&q,start);
	discovered[start] = TRUE;
	while (empty(&q) == FALSE) {
		v = dequeue(&q);
		process_vertex(v);
		processed[v] = TRUE;
		for (i=0; i<g->degree[v]; i++) 
		    if (valid_edge(g->edges[v][i]) == TRUE) {
			if (discovered[g->edges[v][i]] == FALSE) {
				enqueue(&q,g->edges[v][i]);
				discovered[g->edges[v][i]] = TRUE;
				parent[g->edges[v][i]] = v;
			}
			if (processed[g->edges[v][i]] == FALSE) 
				process_edge(v,g->edges[v][i]);
		    }
	}
}

/*
bool valid_edge(edge e)
{
	if (e.residual > 0) return (TRUE);
	else return(FALSE);
}
*/

dfs(graph *g, int v){
	int i;				/* counter */
	int y;				/* successor vertex */
	if (finished) return;		/* allow for search termination */
	discovered[v] = TRUE;
	process_vertex(v);
	for (i=0; i<g->degree[v]; i++) {
		y = g->edges[v][i];
		if (valid_edge(g->edges[v][i]) == TRUE) {
			if (discovered[y] == FALSE) {
				parent[y] = v;
				dfs(g,y);
			} else 
				if (processed[y] == FALSE)
					process_edge(v,y);
		}
		if (finished) return;
	}
	processed[v] = TRUE;
}


find_path(int start, int end, int parents[]){
	if ((start == end) || (end == -1))
		printf("\n%d",start);
	else {
		find_path(start,parents[end],parents);
		printf(" %d",end);
	}
}
