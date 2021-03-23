#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showRandNum(int *arr);
int main(){
  	srand( time(NULL) );
	int x;
	int randNum[10] = {0};
  	/* 指定亂數範圍 */
  	int min = 20;
  	int max = 50;
  	char s[1];
  	
	printf("Press anykey to produce result!\n");
	printf("If tou want to exit, please press \"crtl + c\"!\n");
  	/* 產生 [min , max] 的整數亂數 */
  	while(1){
  		//scan any word to start，run one time to stop
  		scanf("%1s",s);
  		//清除緩沖區 
  		//%後面的*表示將讀取的這些字元丟棄 
  		//遇到'\n'字元時便停止讀取操作 
  		scanf("%*[^\n]");
  		//緩衝區中尚有一個'\n'字元遺留，所以後面的%*c將讀取並丟棄這個遺留的換行符 
  		scanf("%*c");
  		
	  	for(int i = 0; i < 10; i++){
	  		// the number will between 20 and 50
	  		x = rand() % (max - min + 1) + min;
	  		
	  		if(randNum[i] == x){
	  		//do this while until diffrent with last time randNum[i]
	  			while(randNum[i] == x){
	  				randNum[i] = rand() % (max - min + 1) + min;
				}
			}else{
				randNum[i] = x;
			}
	  	}
	  	showRandNum(randNum);
	}
  	
  	return 0;
}

void showRandNum(int *arr){
	
	for (int i = 0; i < 10; i++){
		//if input 3 or 4 multiple, do not display message 
		if(arr[i] % 3 == 0 || arr[i] % 4 == 0){
			printf("NO.%2d = this number does not show \n", i+1);
		}else{
			printf("NO.%2d = %d\n", i+1, arr[i]);
		}
	}
}
