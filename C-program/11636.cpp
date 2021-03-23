#include <stdio.h>

int count_times(int n,int times){

	int base = 1;
	while(1){
		if(base<n){
			base*=2;
			times++;
		}else{
			return times;
		}
		
	}
	
}

int main(){
	
	int n;
	int loop=1;//how many times of copy
	int times=0;
	while(scanf("%d",&n)!=EOF){
		if(n>10000 || n<0){
			return 0;//treminaled
		}
		
		printf("Case %d: %d\n", loop, count_times(n,times));
		loop++;
		times=0;
	}
}
