#include <stdio.h>
#include <stdlib.h>

/* Num, Height, Weight.
 *   0,   H0, W0
 *   1,   H1, W1,
 *   ............ */


int cmpW(const void *p1, const void *p2);
int cmpH(const void *p1, const void *p2);

int main(void){
	const size_t n = 5;
	float A[n][2]= {};
	int i=0;
	for(i=0; i<n; i++){
		printf("W H: ");
		scanf("%f %f", &A[i][0], &A[i][1]);
	}	
	qsort(A, n, sizeof(float)*2, cmpW );
	for(i=0; i<n; i++) printf("%f, %f  ", A[i][0], A[i][1]);
	printf("\n");


	qsort(A, n, sizeof(float)*2, cmpH );
	for(i=0; i<n; i++) printf("%f, %f  ", A[i][0], A[i][1]);
	printf("\n");

}	

int cmpW(const void *p1, const void *p2){
	float *fp1=(float *)p1;	/*p1 will point to A[i], it exit 2 ID, A[i][0] and A[i][1]*/
	float *fp2=(float *)p2;
	
	return fp1[0] - fp2[0];
}

int cmpH(const void *p1, const void *p2){
	float *fp1=(float *)p1;
	float *fp2=(float *)p2;
	
	return fp1[1] - fp2[1];
}
