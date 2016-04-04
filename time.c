#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	struct tm start_time={};
	start_time.tm_hour=23;
	start_time.tm_min=59;

	start_time.tm_hour=start_time.tm_hour+2;
	start_time.tm_min=start_time.tm_min+2;

	printf("Hours:%d    Min:%d\n", start_time.tm_hour, start_time.tm_min);	

}
