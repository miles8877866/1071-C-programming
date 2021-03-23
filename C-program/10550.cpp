#include <stdio.h>

int degreeR(int degree, int var2){
if(degree>=var2){
		degree = 360-(degree-var2);
	}else{
		degree = (var2-degree);
	}
	return degree;
}

int degreeL(int degree, int var2){
if(degree>=var2){
		degree = degree-var2;
	}else{
		degree = 360-(var2-degree);
	}
	return degree;
}

int main(){
	
	int start, pass1, pass2, pass3, degree, degree_total;
	degree_total = 0;
	while(scanf("%d %d %d %d", &start, &pass1, &pass2, &pass3) != EOF){
		if(start==0&&pass1==0&&pass2==0&&pass3==0){
			return 0;
		} 
		degree = start*9;//set initial
		degree_total = 720;
		degree_total += degreeL(degree, pass1*9);
		degree = pass1*9;
		degree_total += 360;
		degree_total += degreeR(degree, pass2*9);
		degree = pass2*9;
		degree_total += degreeL(degree, pass3*9);
		degree = pass3*9;
		printf("%d\n", degree_total);
		
		degree_total =0;//clean
	}
	return 0;
}
