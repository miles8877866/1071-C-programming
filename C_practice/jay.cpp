#include <stdio.h>
#define MAX 65536
#include<algorithm>
int sort(int x[], int n){
    int i, j, temp;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(x[i] > x[j]){
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}
int main(){
    int n;
    int min_mid, max_mid, numbers, diff, i;
    while(scanf("%d", &n) != EOF){
    	int x[n] = {0};
    	int input;
        for(i = 0; i < n; i++){
            scanf("%d", &input);
            x[i] = input;
        }
        sort(x, n);
        
        for(int i=0;i<n;i++){
        	if(n % 2 == 0){
            	min_mid = x[n / 2 - 1];
            	max_mid = x[n / 2];
            	diff = max_mid - min_mid + 1;
            	if(x[n/2-1]==x[i])
				{
					numbers++;
				}
				else if(x[n/2]==x[i])
				{
					numbers++;
				}
        	}else{
            	min_mid = x[(n + 1) / 2];
            	diff = 1;
            	if(x[(n-1)/2]==x[i])
				{
					numbers++;
				}
        	}
		}
        
        printf("%d %d %d\n", min_mid, numbers, diff);
		
    }
}
