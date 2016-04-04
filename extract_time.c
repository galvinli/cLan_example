#include <stdio.h>
#include <stdlib.h>




int main(){
	const *char start_value = "24:55";
	unsigned int start_hour, star_min;

	extract_time_format(start_value, &start_hour, &star_min);
}
