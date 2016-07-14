#include <stdio.h>

/*
 * x^y =  xx^y-1                 y below N  |  even
 *        x^(y>>1) * x^(y>>1)    y below N  |  odd 
 *        1                      y=0 |
 *
 *        e.g. 2^8 = 2^4 * 2^4
 *        		  ->2^2 * 2^2
 *        		          ->2^1 * 2^1
 *        		                   -> 1
 *  for odd input x, y>>1, 
 *  you can see previuos e.g. every time return is x * x.
 *
*/
int main(){
    int x=5, y=4, result=0;

    result= Pow(x,y);
    printf("%d^%d=%d\n",x ,y ,result);

}

int Pow(int x, int y){

	if( y == 0 )
	    return 1;
	if (y & 1)
	    return x*Pow(x, --y);
	else{
	   x = Pow(x, y>>1);
	   return x * x;
	}
}
