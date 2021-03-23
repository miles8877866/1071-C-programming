#include <stdio.h>
#define INF 999999999
int s[20][20]={0};
int m[20][20]={0};

void PRINT_OPTIMAL_PARENS(int i, int j);
int MatrixChainOrder(int p[], int n);
void matmultiply(void);

int main(){
	int num = 0;
	/*
	如果矩陣數為"n"，那行列序應有n+1 
	*/ 
	printf("How many matrix will be input? (n matrix) : ");
	scanf("%d", &num);
	
	int rcl;//輸入的row-colunm-list 
	int list[num+1]={0};//row-colunm-list
	
	printf("Please input the Row-Colum List (must be n+1) :\n");
	for(int i=0;i<num+1;i++){
		scanf("%d", &rcl);
		list[i] = rcl;
	}
	
	printf("Minimum number of multiplications is %d ", 
                       MatrixChainOrder(list, num)); 
    printf("\n");
    for(int i=1;i<num;i++){
    	for(int j=2;j<=num;j++){
    		printf("%d  ", s[i][j]);
		}
		printf("\n");
	}
	for(int i=1;i<num;i++){
    	for(int j=2;j<=num;j++){
    		printf("%6d  ", m[i][j]);
		}
		printf("\n");
	}
	printf("The order is ");
	PRINT_OPTIMAL_PARENS(1, num); 
	
	
	return 0;
} 

void PRINT_OPTIMAL_PARENS( int i, int j) {
    if (i == j)
    {
        printf("%c", i + 64);
    }
    else
    {
        printf("(");
        PRINT_OPTIMAL_PARENS( i, s[i][j]);
        PRINT_OPTIMAL_PARENS( s[i][j] + 1, j);
        printf(")");
    }
}

int MatrixChainOrder(int p[], int n){
  	
    int i, j, k, L, q; 
  
    // cost is zero when multiplying one matrix. 
    for (i=1; i<n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L=1; L<n; L++) 
    { 
        for (i=1; i<n-L+1; i++) 
        { 
            j = i+L; 
            m[i][j] = INF; 
            for (k=i; k<=j-1; k++) 
            { 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) {
                	m[i][j] = q; 
                    s[i][j] = k;
				}
            } 
        } 
    } 
    return m[1][n]; 
}


