#include <stdio.h>
#include <string.h>
int main(){
	
	int n;
	scanf("%d", &n);
	char str[n];
	char c[n];
	
	for(int i=0;i<n;i++){
		str[i] = '0';
	}
	for(int i=0;i<n;i++){
		printf("%c", str[i]);
	}
	printf("\n");
	for(int i=0;i<strlen(str);i++){
		c[i] = str [i];
		
	}
	for(int i=0;i<strlen(str);i++){
		printf("%c", c[i]);
		
	}
} 
