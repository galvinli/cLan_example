#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


int mem_count(char *string1, const char *string2, size_t size);

int main(){
	const char day_array[6]= "Hello\0";
	char string1[] = "Say, Hi! Galivn"; /*If it is a point char, it can't be write.*/	
	const char *string2= "Hello World"; /*point didn't define space.*/
	
	printf("string1:%s\n", string1);
	mem_count(string1, string2, sizeof(string1));
	printf("string1:%s\n", string1);


	//strcpy(&p, day_array[3]);
	//strcpy(p_buffer, day_array[3]);

	//printf("p= %c\n", p);
	//printf("p_buffer= %s\n", p_buffer);
	//printf("sizeof= %lu\n", sizeof(day_array));
	
	//for (int i=0; i<6; i++) printf(" 0x%2x", day_array[i]);

	//for (int i=0; i<6; i++) printf(" %c", day_array[i]);
		
}


int mem_count(char *string1, const char *string2, size_t size){

	printf("size= %lu\n", size); /*It will show memory addr size*/
	memcpy( string1, string2, size);

	return 0;

}
