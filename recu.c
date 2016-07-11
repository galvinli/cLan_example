#include <stdio.h>


int main(){

    int n=10, result=0;
	
    result = mul(n);
    printf("%d!=%d\n", n, result);
}

int mul(int n){
	    int end=1;

    if(n == 0){
	    printf("%d\n",end);
	    return end;
    }		    
    else{
	    printf("%dx",n);
	    return (n * mul(n-1));
    }	    
            

}
