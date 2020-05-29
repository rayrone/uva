#include<stdio.h>

#define MAX 100

long binomial_coefficient(int n, int m){
	 
	 int i,j;
	 long bc[MAX][MAX];
	 
	 for(i = 0 ; i <= n ; i++){
	 		 bc[i][0] = 1;
	 		 bc[i][i] = 1;
	 }
	 
	 for(i = 1 ; i <= n ; i++){
	 		 for(j = 1 ; j < i ; j++){
			 		 /* dynamic programming */
			 		 bc[n][m] = bc[n - 1][m - 1] + bc[n - 1][m];
	 		 }
	 }
	 
	 return bc[n][m];
}

int main(){
	 
	 int i = 0;
	 int j = 0;
	 
	 for(i = 0 ; i <= 10 ; i++) {
	 		 for(j = 0 ; j <= 10 ; j++) {
	 		 		 printf("%d %d %ld\n", i, j, binomial_coefficient(i, j));
			 }
	 }
	 
	 scanf("%d", &i);
	 
	 return 0;	 
}
