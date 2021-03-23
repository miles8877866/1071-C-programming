#include<stdio.h>

int main(){
	//a is the number will be test 
	double a;
	double lg, ng;
	
	printf("Find square root of ");
	scanf ("%lf", &a);
	lg = a;
	while (1){
		
		printf("LG : %g, ", lg);
		ng = 0.5 * (lg + a / lg) ;
		printf("NG : %g\n", ng);
		
		if(ng - lg < 0.000005 && lg - ng < 0.000005)
			break;
		lg = ng;
	}
	printf("The square root of %g is %g\n", a, lg);
}
