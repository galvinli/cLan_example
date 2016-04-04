#include <stdio.h>
#include <stdlib.h>

void fuct_sum(){
	static int a=12;
	a++;
	printf("%d\n",a);
	
}

int main(){
	fuct_sum();
	fuct_sum();
	return 0;
}
