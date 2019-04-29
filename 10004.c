#include<stdio.h>

#define MAXV		200		/* maximum number of vertices */
#define MAXDEGREE	200		/* maximum outdegree of a vertex */
#define BOOL int

/* 10004 - Bicoloring */

typedef struct {
   int painted[MAXV];    
	int edges[MAXV][MAXDEGREE];	/* adjacency info */
	int degree[MAXV];		/* outdegree of each vertex */
	int nvertices;			/* number of vertices in the graph */
} graph;

enum { FALSE, TRUE};

int BICOLORABLE;

void initialize_graph(graph *g){
	int i;				/* counter */
	g -> nvertices = 0;
	for (i = 0 ; i <= MAXV ; i++) {
        g->degree[i] = 0;
        g->painted[i] = 0;
    }    
}

void insert_edge(graph *g, int x, int y, BOOL directed){
	g->edges[x][g->degree[x]] = y;
	g->degree[x] ++;
	if (directed == FALSE) insert_edge(g,y,x,TRUE);
}

void read_graph(graph *g, BOOL directed){
      int i;				/* counter */
	  int m;				/* number of edges */
	  int x, y;			/* vertices in edge (x,y) */

     initialize_graph(g);
	  scanf("%d", &(g->nvertices));
	  if(g->nvertices == 0) 
           exit(0);
      scanf("%d", &m);      
	  for (i = 0 ; i < m ; i++) {
	       scanf("%d %d", &x, &y);
		   insert_edge(g, x, y, directed);
	  }
}

void paint(graph *g, int v, int color){
       int i;
       
       if(g->painted[v] == -color)
            BICOLORABLE = FALSE;
       if(g->painted[v] != 0)
            return;
       g->painted[v] = color;
        
       for(i = 0 ; i < g->degree[v] ; i++)
            paint(g, g->edges[v][i], -color);
       
       return;     
}

int main(){

       graph g;
              
       while(1){
            BICOLORABLE = TRUE;    
            read_graph(&g, FALSE);
            paint(&g, 1, 1);
            if(BICOLORABLE)
               puts("BICOLORABLE.");
            else
               puts("NOT BICOLORABLE."); 
       }
    return 0;
}
