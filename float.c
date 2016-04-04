#include <stdio.h>
#include <stdlib.h>
#include <float.h>


int main(){
	float a = 1.0f;
	double b = 1.0; /*default 常數 is double*/
	printf("%0.20f\n", a);	/*%f 8 byte */
	printf("%0.20f\n", b);	/*%f 8 byte */

}	
