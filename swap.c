#include <stdio.h>
#include <stdlib.h>

int Swap( void *a, void *b, int n){

	char *ca = (char *)a;
	char *cb = (char *)b;
	int i; char t;

	for(i=0; i<n; i++){
	        t = ca[i];
		ca[i] = cb[i];
		cb[i] = t;
	}

}

int main(){
	double x=1230.123, y=5678.234;

	printf("x: %f,  y: %f\n", x, y);
	Swap(&x, &y, sizeof(x));
	printf("x: %f,  y: %f\n", x, y);

}
