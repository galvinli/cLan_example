#include <stdio.h>
#include <stdlib.h>


int FAdd(int x, int y){
	return x + y;
}

int FSub(int x, int y){
	return x - y;
}

void FHello(){
	printf("Hello\n");
}

void FHi(){
	printf("Hi\n");
}

int main(){
	int (*pf1) (int, int)=NULL;
	void (*pf2) ()=NULL;
	int a =10, b=2;

	pf1=&FAdd;
	printf("%d\n", pf1(a, b) );	

	pf1=FSub;
	printf("%d\n", pf1(a, b) );	

	pf2=&FHello;
	pf2();

	pf2=&FHi;
	pf2();
}

