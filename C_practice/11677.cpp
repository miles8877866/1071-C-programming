#include <stdio.h>

 int main(){//Alarm clock
 	
 	int h1, m1;//current time
 	int h2, m2;//set clock time
 	int total=0;//total time can sleep(min)
 	
 	while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2)){
 		if(h1==0 && m1==0 && h2==0 && m2==0){//������� 
 			break;
		 }
		 
 		if(h1>=h2){//�]�w���ɶ��i���{�b�p�ε���A��ܹj�� 
 			if(h1==h2){//��ɶ��@�ˡA�Ӥ������p�]�O�j�� 
 				if(m1>m2){
 					total = 1440 - (m1 - m2);//a day - (now-set)
				 }else{//�]�w���O�{�b���� 
				 	total = m2 - m1;
				 }
			 }else{//h1 > h2
			 	total = 1440 - 60 * (h1 - h2) - (m1 - m2);
			 }
		 }else{//���ΦҼ{�j�� 
		 	total = 60 * (h2 - h1) - (m2 - m1);
		 }
 		
 		printf("%d\n", total);
	 }
 	
 	return 0;
 }
