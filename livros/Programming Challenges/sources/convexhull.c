#include<stdio.h>
#include<stdlib.h>

#define BOOL int
#define EPSILON 0.0001
#define MAX_POINTS 100

/* ----------------------- Declarações das estruturas ----------------------- */

typedef struct {
     int x;
     int y;
} point;

typedef struct {
     int n;
     point p[MAX_POINTS];
} polygon;

/* -------------------- Declarações das variáveis globais ------------------- */

point first_point;

/* --------------------------- funções auxiliares --------------------------- */

void copy_point(point p1, point *p2) {
	  p2 -> x = p1.x;
	  p2 -> y = p1.y;
}

BOOL leftlower(point *p1, point *p2) {
	  if((*p1).x < (*p2).x) 
	        return -1;
	  if((*p1).x > (*p2).x)
	        return 1;
     /* em caso de empate utiliza-se a coordenada a menor coordenada y com critério */
     if((*p1).y < (*p2).y)
	        return -1;
     if((*p1).y > (*p2).y)
	        return 1;
	        
     return 0;
}

double signed_triangle_area(point a, point b, point c) {
     return ( (a.x * b.y - a.y * b.x + a.y * c.x - a.x * c.y + b.x * c.y - c.x * b.y) / 2.0 );
}

BOOL collinear(point a, point b, point c) {
	  double signed_triangle_area();
	  
	  return fabs(signed_triangle_area(a, b, c)) <= EPSILON;
}

double distance(point a, point b) {
     return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void print(polygon *fecho) {
	  int i;
	  for(i = 0 ; i < fecho -> n ; i ++){
         printf("%d %d\n", fecho -> p[i].x, fecho -> p[i].y);
	 }
}

/* ------------------ funções para calcular o fecho convexo ----------------- */

BOOL ccw(point a, point b, point c) {
	  double signed_triangle_area();
	  
	  return (signed_triangle_area(a, b, c) > EPSILON);
}

BOOL smaller_angle(point *p1, point *p2) {
	  if(collinear(first_point, *p1, *p2)) {
	      if(distance(first_point, *p1) <= distance(first_point, *p2))
	          return -1;
         else
             return 1;
	  }
	  if(ccw(first_point, *p1, *p2))
	      return -1;
     else
     		return 1;
}

void sort_and_remove_duplicates(point in[], int *n) {
	  int i;
	  int oldn;
	  int hole;
	  BOOL leftlower();
	  
	  qsort(in, *n, sizeof(point), leftlower);
	  
	  oldn = *n;
	  hole = 1;
	  
	  for(i = 1 ; i < (oldn - 1) ; i++) {
           if(in[hole - 1].x == in[i].x && in[hole - 1].y == in[i].y)
                 (*n)--;
           else {
			  		 copy_point(in[i], &in[hole]);
			  		 hole++;
			  }
	  }
	  copy_point(in[oldn - 1], &in[hole]);
}

void convex_hull(point in[], int n, polygon *hull) {
     int i;
     int top;
     BOOL smaller_angle();
     
     if(n <= 3) {
         for(i = 0 ; i < n ; i++)
			    copy_point(in[i], &(hull -> p[i]));
	      hull -> n = n;
			return;
     }
     
     //printf("antes n = %d\n", n);
     sort_and_remove_duplicates(in, &n);
     //printf("depois n = %d\n", n);
     copy_point(in[0], &first_point);
     //printf("in[0] %d %d\n", in[0].x, in[0].y);
     //printf("first_point %d %d\n", first_point.x, first_point.y);
     
     qsort(&in[1], n - 1, sizeof(point), smaller_angle);
     
     copy_point(first_point, &(hull -> p[0]));
     copy_point(in[1], &(hull -> p[1]));
     copy_point(first_point, &in[n]);
     
     top = 1;
     i = 2;
     
     while(i <= n) {
         if(!ccw(hull -> p[top - 1], hull -> p[top], in[i]))
		       top--;
         else {
	  		    top++;
	  		    copy_point(in[i], &(hull -> p[top]));
	  			 i++;		    
	  		}
	  }
	  
	  hull -> n = top;
}

int main() {
    
    int i, n;
    point p[14];
    polygon fecho;
    
    p[0].x = 1; p[0].y = 1;
    p[1].x = 1; p[1].y = 2;
	 p[2].x = 1; p[2].y = 3;
	 p[3].x = 2; p[3].y = 0;
	 p[4].x = 2; p[4].y = 1;
	 p[5].x = 2; p[5].y = 2;
	 p[6].x = 2; p[6].y = 3;
	 p[7].x = 2; p[7].y = 4;
	 p[8].x = 3; p[8].y = 1;
	 p[9].x = 3; p[9].y = 2;
	 p[10].x = 3; p[10].y = 3;
	 p[11].x = 4; p[11].y = 2;
	 p[12].x = 0; p[12].y = 2;
	 p[13].x = 0; p[13].y = 2;
 	 n = 14;
	 
	 convex_hull(p, n, &fecho);
	 
	 print(&fecho);
	 puts("");
    system("pause");
}
