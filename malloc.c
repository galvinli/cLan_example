#include <stdio.h>
#include <stdlib.h>



int main(){
	/*10 characters, malloc will return first slot's memory address
	 * and datetype is void, so we have to cast to what we want
	 * datetype, if malloc fail will return a 'NULL' memory address.
	 * so we can use it*/
	char *pc = (char *)malloc(sizeof(char)* 10);
	
	if (pc !=NULL){
		for(int i=0;i<10;i++){
			pc[i] = i + 65;
			printf("%d ", pc[i]);
		}	
	}	
		
	printf("\n");
	free(pc);
}
