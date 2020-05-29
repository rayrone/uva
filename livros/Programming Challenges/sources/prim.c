/*	Compute minimum spanning trees of graphs via Dijkstra/Prim's algorithm.

	www.programming-challenges.com
*/

#include <stdlib.h>
#include "bool.h"
#include "wgraph.h"

#define MAXINT	100007

int parent[MAXV];               /* discovery relation */


/************************************************************/


prim(graph *g, int start)
{
	int i,j;			/* counters */
	bool intree[MAXV];		/* is the vertex in the tree yet? */
	int distance[MAXV];		/* distance vertex is from start */
	int v;				/* current vertex to process */
	int w;				/* candidate next vertex */
	int weight;			/* edge weight */
	int dist;			/* best current distance from start */

	for (i=1; i<=g->nvertices; i++) {
		intree[i] = FALSE;
		distance[i] = MAXINT;
		parent[i] = -1;
	}

	distance[start] = 0;
	v = start;

	while (intree[v] == FALSE) {
		intree[v] = TRUE;
		for (i=0; i<g->degree[v]; i++) {
			w = g->edges[v][i].v;
			weight = g->edges[v][i].weight;
			if ((distance[w] > weight) && (intree[w] == FALSE)) {
				distance[w] = weight;
				parent[w] = v;
			}
		}

		v = 1;
		dist = MAXINT;
		for (i=1; i<=g->nvertices; i++) 
			if ((intree[i] == FALSE) && (dist > distance[i])) {
				dist = distance[i];
				v = i;
			}
	}
}

main()
{
	graph g;
	int i;

	read_graph(&g,FALSE);

	prim(&g,1);

printf("Out of Prim\n");

        for (i=1; i<=g.nvertices; i++) {
		/*printf(" %d parent=%d\n",i,parent[i]);*/
                find_path(1,i,parent);
	}
        printf("\n");

}

