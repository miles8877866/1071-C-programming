#include<stdio.h>

int main(){
	char p[10];//can input just one char, but that's string type 
	int c;
	int count;
	printf("¿é¤J¼Æ¦r:");
	scanf("%s", &p);//the digit:1 is used to restrict digit

	if(p[0]=='x'||p[0]=='o'||p[0]=='*'){
		scanf("%d", &c);//set c value 
		count = 0;//set initial value
		while(count<c){//run c times, use count++ to control
		printf("%c", p[0]);//use %c to put one char of string
		count++;
		}
	}else{
		printf("\nexit\n");
	}
	
	return 0;
}
