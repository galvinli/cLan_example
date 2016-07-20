#include <stdio.h>
#include <string.h>

//int ReplaceStr(char*,const char*, const char*); 

int main(){
	char s1[30] = "AABB123456XXAADDCCAA";
	char *s2="AA", *s3="XX";
	int result=0;
	printf("s1: %s\n", s1);

	result=ReplaceStr(s1, s2, s3);

	printf("s1: %s\n", s1);
}



int ReplaceStr(char *s1, const char *s2, const char *s3){
	int n1=0, n2=0, n3=0, count=0;
	char *sNext=NULL;

	if( s1 == NULL || s2 == NULL || s3 == NULL) return 0;
	n1 = strlen(s1), n2 = strlen(s2), n3 = strlen(s3);
	
	if(!n1 || !n2) return 0;

	sNext = strstr(s1, s2);
	
	if(sNext != NULL){
		memcpy(sNext, s3, n3);
		sNext += strlen(s3);
		count += ReplaceStr(sNext, s2, s3) +1;
	}

	return count;
}	
