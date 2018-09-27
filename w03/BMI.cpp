#include<stdio.h>
#include<stdlib.h>

int main(){
    double m,kg,BMI;
	
	
	printf("Enter your height weight:");
	scanf("%f %f",&m,&kg);
	BMI=kg/(m*m);
	while(kg>=0&m>=0){
		if(BMI<18.5){
			printf("體重過輕");
		}
		else if(18.5<=BMI<24){
			printf("正常範圍");
		}
		else if(24<=BMI<27){
			printf("過重");
		}
		else if(27<=BMI<30){
			printf("輕度肥胖");
	    }
	    else if(30<=BMI<35){
			printf("中度肥胖");
	    }
	    else if(BMI>=35){
			printf("重度肥胖");
	    } 
	    printf("Enter your height weight:");
		scanf("%d %d",&m,&kg);
	} 
	return 0;
} 
