#include <stdio.h>

int main(){
	char *profile_name = "Daily00to08";
	char *day_string = "1111111";
	char *start_time = "08:00";
	char *end_time = "18:00";	
	char nvram_buf[64]={};
	char schedule_list[32]={};
	int index=0;
	
	sprintf( schedule_list, "schedule-rule_%02d", index);
	sprintf( nvram_buf, "%s/%s/%s/%s", profile_name, day_string, start_time, end_time);
	printf("schedule_lise:  %s\n", schedule_list);
	printf("nvram_buf: %s\n", nvram_buf);

}
