#include <stdio.h>
#include <stdlib.h>

void ashow(const char *value){
	printf("%s\n", value);
	printf("%c \n", *value);
	printf("%d\n", atoi(value));
}
int main(){
	int a=0;
	char b;
	b = (a==1) ? '1':'0';
	ashow(&b);
}

