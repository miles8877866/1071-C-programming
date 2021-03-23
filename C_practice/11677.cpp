#include <stdio.h>

 int main(){//Alarm clock
 	
 	int h1, m1;//current time
 	int h2, m2;//set clock time
 	int total=0;//total time can sleep(min)
 	
 	while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2)){
 		if(h1==0 && m1==0 && h2==0 && m2==0){//限制條件 
 			break;
		 }
		 
 		if(h1>=h2){//設定的時間可能比現在小或等於，表示隔天 
 			if(h1==h2){//當時間一樣，而分鐘較小也是隔天 
 				if(m1>m2){
 					total = 1440 - (m1 - m2);//a day - (now-set)
				 }else{//設定的是現在之後 
				 	total = m2 - m1;
				 }
			 }else{//h1 > h2
			 	total = 1440 - 60 * (h1 - h2) - (m1 - m2);
			 }
		 }else{//不用考慮隔天 
		 	total = 60 * (h2 - h1) - (m2 - m1);
		 }
 		
 		printf("%d\n", total);
	 }
 	
 	return 0;
 }
