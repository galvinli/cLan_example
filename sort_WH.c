#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/* Num, Height, Weight.
 *   0,   H0, W0
 *   1,   H1, W1,
 *   ............ */

#define QSORT 1

#if QSORT
#define MIN_NUM 0	/* if MIN == 0 max number will be first.*/
int cmpW(const void *p1, const void *p2);
int cmpH(const void *p1, const void *p2);
#endif

typedef struct student{
	float H;
	float W;
}std;	

/*Dynamic n member, entry each member's H and W, and printf it.*/
int main(void){
	int i=0;
	size_t n = 0;

	std *A=NULL;

	printf("n="); scanf("%zu",&n);
	
	A=(std *)malloc(sizeof(std)*n);

	memset(A, 0, (sizeof(std)*n));

	for(i=0; i<n; i++){
	//	A+=i;	/*offest*/
		printf("W H: ");
		scanf("%f %f", &A[i].W, &A[i].H);
	}

	//i--; 
	//A-=i;

	for(i=0; i<n; i++) {
	//	A+=i;
		printf("%f, %f ", A[i].W, A[i].H);
	}
	
	printf("\n");
	//i--; 
	//A-=i;

	
#if QSORT
	printf("cmpW: \n");
	qsort(A, n, sizeof(std), cmpW );
	for(i=0; i<n; i++) printf("%f, %f  ", A[i].W, A[i].H);
	printf("\n");


	printf("cmpH: \n");
	qsort(A, n, sizeof(std), cmpH );
	for(i=0; i<n; i++) printf("%f, %f  ", A[i].W, A[i].H);
	printf("\n");
#endif	
	if(A) free(A);

return 0;

}	


#ifdef QSORT

int cmpW(const void *p1, const void *p2){
	const std *fp1=(const std *)p1;	/*p1 will point to A[i], it exit 2 ID, A[i][0] and A[i][1]*/
	const std *fp2=(const std *)p2;
	float ans=0;
	ans = fp1->W - fp2->W;
	ans = (MIN_NUM == 1) ? ans : -ans;

	return ans;
}

int cmpH(const void *p1, const void *p2){
	const std *fp1=(const std *)p1;
	const std *fp2=(const std *)p2;
	float ans=0;
	ans = fp1->H - fp2->H;
	ans = (MIN_NUM == 1) ? ans : -ans;

	return ans;
}

#endif
