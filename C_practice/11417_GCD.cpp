#include <stdio.h>

int GCD(int i, int j){
	if(i&&j)
		while((i%=j) && (j%=i));
		return i+j;
} 

int main(){
	
	int N, G;
	while(1){
		
		scanf("%d", &N);
		if(N==0) break;
		if(N<=1 || N >= 501) break;//restrict
		
		G=0;
		for(int i=1;i<N;i++){
			for(int j=i+1;j<=N;j++){
				G += GCD(i, j);
			}
		}
		printf("%d\n", G);
		
	}
	
	return 0;
}
