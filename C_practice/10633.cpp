#include <stdio.h>

int main(){
	long long int N, M;
	long long int X;
	/*
	X = N - M
	N = 10M + k
	X = 10M + k -M = 9M-k
	M = (X - k) / 9
	-->0<=k<=9
	*/
	
	while(scanf("%lld", &X)!=EOF){
		if(X==0) break;
		if(X<10) break;//restrict

		bool first = true;
		for (long long int i = 9; i >= 0; --i)
            if ((X - i) % 9 == 0)
            {
                if (!first)
                    printf(" ");
                printf("%lld", (X - i) / 9 * 10 + i);
                first = false;
            }
            printf("\n");
	}
	
	return 0;
}
