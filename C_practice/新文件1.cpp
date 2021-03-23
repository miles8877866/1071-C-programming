#include <stdio.h>

int main(){
    int T, M, N, Q, i, j, r, c;
    int step[4];
    int count = 1;
    int check = 1;
    char grid[22][22];
    scanf("%d", &T);
    while(T--){
        
        scanf("%d %d %d", &M, &N, &Q);
        for(i = 0; i < M; i++){
            char x = getchar();
            for(j = 0; j < N; j++){
                scanf("%c", &grid[i][j]);
            }
        }
        
        for(i = 0; i < Q; i++){
        count = 0;
        check = 1;
            scanf("%d %d", &r, &c);
            while(check){
				if(!((r >= count) && (r + count < M) && (c >= count) && (c + count < N))){
					check = 0;
					break;
				}
//            printf("a%d\n", count);
                for(j = r - count; j <= r + count; j++){
//                printf("grid[%d][%d] : %c\n", j, c + count, grid[j][c + count]);
                    if(grid[j][c + count] != grid[r][c]){
                    check = 0;
                    
                    break; 
}
//printf("grid[%d][%d] : %c\n", j, c - count, grid[j][c - count]);
                    if(grid[j][c - count] != grid[r][c]){
                    check = 0;
                    break; 
}
                }
                if(check == 0) break;
                for(j = c - count; j <= c + count; j++){
                    if(grid[r + count][j] != grid[r][c]){
                    check = 0;
                    break; 
}
                    if(grid[r - count][j] != grid[r][c]){
                    check = 0;
                    break; 
}
                }
                if(check == 0) break;
//                printf("b%d\n", count);
count++;
            }
            if(check == 0){
            	count--;
			}
            printf("%d\n", (2 * count) + 1);
        }
    }

}
