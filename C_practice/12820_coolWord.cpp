#include <stdio.h>
#include <string.h>

int main(){
	
	int n;//how many case
	char str[30];
	int count[26] = {0};
	char c[26];
	for(int i=0;i<26;i++){
		c[i]='0';
	}
	int flag=1;
	int cooltimes=0;
	int times=0;
	
	while(scanf("%d", &n)!=EOF){
		
		while(n>0){
			scanf("%s", str);
			
			for(int i=0;i<strlen(str);i++){//處理陣列 
				for(int j=0;j<26;j++){
					if(str[i]==c[j]){
						count[j]+=1;//同位置 
						break;
					}
					if(c[j]=='0'){
						c[j] = str[i];
						count[j]+=1;
						break;
					}
				}
			}
			
			for(int i=0;i<26;i++){
				if(count[i]!=0){
					for(int j=i+1;j<26;j++){
					if(count[j]!=0){
							if(count[i]==count[j])
							flag=0;
						}
					}
				}
			}
			//只檢測第二個，確認只有一種字母
			if(count[1]==0){
				flag=0;
			} 
			for(int i=0;i<26;i++){//歸零 
				printf("%c", c[i]);
			}
			printf("\n");

			
			
			for(int i=0;i<26;i++){//歸零 
				printf("%d", count[i]);
			}
			printf("\n");

			for(int i=0;i<strlen(str);i++){
				str[i]='0';
			}
			for(int i=0;i<26;i++){
				c[i]='0';
				count[i]=0;
			}
			
			//check
			if(flag==1){
				cooltimes+=1;
			}
			
//			printf("flag:%d\n", flag);
			flag=1;//initial
			n--; 
			
		}
		
		times+=1;
		
		printf("Case %d: %d\n",times, cooltimes);
		
		cooltimes=0;
	}
}

