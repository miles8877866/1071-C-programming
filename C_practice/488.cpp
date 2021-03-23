#include <stdio.h>

int main(){
	int	times;
	scanf("%d", &times);//how many times to read
	
	printf("\n");
	int A, F;
	
	while(times>0){
		scanf("%d", &A);
		scanf("%d", &F);
		
		if(A>9) break;//restrict
		
		printf("\n");
	for(int k=0;k<F;k++){//compare frequency times
		for(int i=1;i<=A;i++){//drow the wave
			for(int j=1;j<=i;j++){
				printf("%d", i);
			}
			printf("\n");
		}
		for(int i=A-1;i>0;i--){
			for(int j=1;j<=i;j++){
				printf("%d", i);
			}
			printf("\n");
		}
		printf("\n");
	}	
		
		times--;//do 1 loop, minus 1
	}
	
} 
