#include <stdio.h>
#include <stdlib.h>



int main(){
	unsigned char start_min=40, start_hour=8;
	unsigned char end_min=40, end_hour=14;
	unsigned char dis_min=41, dis_hour=14;
	char sche_file[] = "/Users/galvin/tmp/sche_rule.txt";
	//int start_time=0;
	FILE *sche_rule;
	
	//start_time = ((((int )hour&0xff) << 8) + ((int )min&0xff));

	//printf("Hour_size:%lu\n", sizeof((int )hour));

	//printf("start_time: %d\n", start_time);
	printf("Start Time: %2d:%2d \n", start_hour, start_min);
	printf("End Time: %2d:%2d \n", end_hour, end_min );	
	
	sche_rule=fopen(sche_file, "w+");
	if (sche_rule == NULL) return 0;
	fprintf( sche_rule, "%d-59 %d * * * ifconfig ath0 up\n", start_min, start_hour);	
	fprintf( sche_rule, "* %d-%d * * * ifconfig ath0 up\n", start_hour, end_hour-1);	
	fprintf( sche_rule, "0-%d %d * * * ifconfig ath0 up\n", end_min, end_hour);	
	fprintf( sche_rule, "%d %d * * * ifconfig ath0 down\n", dis_min, dis_hour);	
       	fclose (sche_rule);	
	
}
