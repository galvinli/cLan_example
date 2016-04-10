#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	int H;
	int W;
}std;


/*you can sepqrate typedef and struct, for example 
 * define struct first
 * seconds typedef it*/

int main(){

std A[2];
std* B=NULL;

A[0].H=72;
A[0].W=82;
A[1].H=172;
A[1].W=182;

printf("A[0].H=%d  A[0].W:%d \n", A[0].H, A[0].W);
printf("A[1].H=%d  A[1].W:%d \n", A[1].H, A[1].W);

B=A;
B->H = 88;
B->W = 188; 	

printf("A[0].H=%d  A[0].W:%d \n", A[0].H, A[0].W);
printf("B->H=%d  B->W:%d \n", B->H, B->W);
B++;
printf("B->H=%d  B->W:%d \n", B->H, B->W);

return 0;

}



