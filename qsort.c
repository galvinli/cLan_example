#include <stdio.h>
#include <stdlib.h>

/*
 * void qsort ( 
 * 	void* base,				// the array to be sorted
 * 	size_t n,				//number of elements
 * 	size_t size,				//size in bytes of each element	
 * 	int (*comp) (const void*, const void*) 	//element comparator
 * */

int cmp(const void *p1, const void *p2){
	return *(int *)p1 - *(int *)p2;
}
int pmc(const void *p1, const void *p2){
	return *(int *)p2 - *(int *)p1;
}

int main(){
	int A[5]={4, 5, 3, 2, 7};

	printf("A[5]: ");	
	for(int i=0; i<5 ; i++)	printf("%d ", A[i]);
	printf("\n");	

	qsort(A, 5, sizeof(int), cmp);

	printf("A[5]: ");	
	for(int i=0; i<5 ; i++)	printf("%d ", A[i]);
	printf("\n");	
	
	qsort(A, 5, sizeof(int), pmc);

	printf("A[5]: ");	
	for(int i=0; i<5 ; i++)	printf("%d ", A[i]);
	printf("\n");	
}
