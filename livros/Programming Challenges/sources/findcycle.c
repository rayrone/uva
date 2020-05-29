/*	Identify a cycle in a graph, if one exists. */

#include "bool.h"
#include "graph.h"

extern bool processed[];	/* which vertices have been processed */
extern bool discovered[];	/* which vertices have been found */
extern int parent[];		/* discovery relation */

extern bool finished;		/* flag for early search cutoff */


process_vertex(int v){
}

process_edge(int x, int y){
	if (parent[x] != y) {	/* found back edge! */
		printf("Cycle from %d to %d:",y,x);
		find_path(y,x,parent);
		printf("\n\n");
		finished = TRUE;
	}
}

bool valid_edge(int e){
        return (TRUE);
}

main(){
	graph g;
	int i;
	read_graph(&g,FALSE);
	print_graph(&g);
	initialize_search(&g);
	dfs(&g,1);
}
