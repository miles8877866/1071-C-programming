#include <stdio.h>

int main(){
	
	long long int var1, var2;
	while(scanf("%lld %lld", &var1, &var2)!=EOF){
		if(var1>=var2){
			printf("%lld\n",var1-var2);
		}else{
			printf("%lld\n",var2-var1);
		}
	}
	return 0;
}
