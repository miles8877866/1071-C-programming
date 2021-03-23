#include <stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int s1,s2,s3,s4;//4side
	while(n--){
		
		scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
		if(s1==s2&&s2==s3&&s3==s4){
			printf("square\n");
		}else if(s1==s3&&s2==s4||s1==s4&&s2==s3||s1==s2&&s3==s4){
			printf("rectangle\n");
		}else if(s1+s2+s3>s4&&s2+s3+s4>s1&&s1+s2+s4>s3&&s1+s3+s4>s2){
			printf("quadrangle\n");
		}else{
			printf("banana\n");
		}
	}
	return 0;
}
