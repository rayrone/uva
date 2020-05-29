/* A generic implementation of string comparison via dynamic programming */

#include <string.h>

#define MAXLEN          101     /* longest possible string */

#define MATCH           0       /* enumerated type symbol for match */
#define INSERT          1       /* enumerated type symbol for insert */
#define DELETE          2       /* enumerated type symbol for delete */

typedef struct {
        int cost;               /* cost of reaching this cell */
        int parent;             /* parent cell */
} cell;

enum{ FALSE , TRUE};

cell m[MAXLEN+1][MAXLEN+1];	/* dynamic programming table */


int string_compare(char *s, char *t){
	int i,j,k;		/* counters */
	int opt[3];		/* cost of the three options */
	for (i=0; i<MAXLEN; i++) {
		row_init(i);
		column_init(i);
	}
	for (i=1; i<strlen(s); i++)
		for (j=1; j<strlen(t); j++) {
			opt[MATCH] = m[i-1][j-1].cost + match(s[i],t[j]);
			opt[INSERT] = m[i][j-1].cost + indel(t[j]);
			opt[DELETE] = m[i-1][j].cost + indel(s[i]);
			m[i][j].cost = opt[MATCH];
			m[i][j].parent = MATCH;
			for (k=INSERT; k<=DELETE; k++)
				if (opt[k] < m[i][j].cost) {
					m[i][j].cost = opt[k];
					m[i][j].parent = k;
				}
		}
	goal_cell(s,t,&i,&j);
	return( m[i][j].cost );
} 

reconstruct_path(char *s, char *t, int i, int j){
/*printf("trace (%d,%d)\n",i,j);*/
	if (m[i][j].parent == -1) return;
	if (m[i][j].parent == MATCH) {
		reconstruct_path(s,t,i-1,j-1);
		match_out(s, t, i, j);
		return;
	}
        if (m[i][j].parent == INSERT) {
                reconstruct_path(s,t,i,j-1);
		insert_out(t,j);
		return;
        }
        if (m[i][j].parent == DELETE) {
                reconstruct_path(s,t,i-1,j);
		delete_out(s,i);
		return;
        }
}

print_matrix(char *s, char *t, bool costQ){
	int i,j;			/* counters */
	int x,y;			/* string lengths */
	x = strlen(s);
	y = strlen(t);
	printf("   ");
	for (i=0; i<y; i++)
		printf("  %c",t[i]);
	printf("\n");
	for (i=0; i<x; i++) {
		printf("%c: ",s[i]);
		for (j=0; j<y; j++) {
			if (costQ == TRUE)
				printf(" %2d",m[i][j].cost);
			else
				printf(" %2d",m[i][j].parent);
		}
		printf("\n");
	}
}

