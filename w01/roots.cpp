#include<stdio.h>
#include<math.h>


int main(){
	int a,b,c;
	double X1 , X2;
	printf("Enter a b c");
	scanf("%d %d %d,&a,&b,&c");
	printf("For equation ax^2 -bx+c=0, two roots are");
	if(b*b-4*a*c>=0){
		X1 = (-b+sqrt(b*b-4*a*c))/(2*a);
	    X2 = (-b-sqrt(b*b-4*a*c))/(2*a);
		printf("X1=%.1f\n",X1);
		printf("X2=%.1f\n",X2);
	}
	else{
		printf("no real roots");
	}
}

