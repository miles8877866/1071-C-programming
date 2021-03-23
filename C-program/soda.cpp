#include <stdio.h>

int main(){
	int N; 		// number of test case
	int e; 		// number of empty bottles at the start of the day
	int f; 		// number of empty bottles found during the day
	int c;		// number of bottles required to buy a new soda.
	int total;	// extra soda that he drank.
	
	scanf("%d", &N);
	while(N--){
		scanf("%d %d %d", &e, &f, &c);
		
		total = 0;
		e = e + f;
		
		//not enough to change 
		while((f = e / c) != 0){
			total += f, e = f + (e % c);
		}
		
		printf("%d\n", total);
	}
	
	return 0;
}
