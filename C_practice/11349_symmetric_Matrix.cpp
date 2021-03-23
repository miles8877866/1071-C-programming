#include <stdio.h>
#include <string.h>

int main(){
	
	char tm[10];
	int n=0;//n<=300
	int size = 0;
	int time = 1;
	
	scanf("%d", &n);
	while(n--){
		
		scanf("%s%s%d", tm, tm, &size);
		
		long long int m[size][size];
		long long int num;
		int flag = 0;
		
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				scanf("%lld", &num);
				m[i][j] = num;
			}
		}
		
		for(int i = 0; i < size; i++){
     		for(int j = 0; j < size; j++){
          		int r = size - i - 1;
          		int c = size - j - 1;
          		if(m[i][j] != m[r][c] || m[i][j] < 0 || m[r][c] < 0){
          			i = j = flag = size;
              		break;
				}
        	}  
		}
		
		if(flag == size)
			printf("Test #%d: Non-symmetric.\n", time++);   
  		else
		 	printf("Test #%d: Symmetric.\n" , time++); 
		
		flag = 0;
	}
	return 0;
}

