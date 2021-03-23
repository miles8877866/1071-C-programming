#include <stdio.h>
#include <windows.h>
/*
3桿河內塔 ，可以多環 

*len: 長度，由左到右 
*width: 寬度，由上到下  
*left: 左邊區塊
*mid: 中間區塊
*right: 右邊區塊
*time: 延遲時間 
*/
int len, width, left, mid, right, time;

char map[80][100];

int next[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //上0下1左2右3；

int turn[2][3] = {{0, 3, 1},  //a -> b   b -> c a -> c  上右下
                  {0, 2, 1}}; //b -> a  c -> b  c -> a	上左下
                  
int hanoi_count = 0;//計算搬運幾次: 應為最小2^n - 1 

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
/*
畫出搬運環境 

*/ 
int init(){
	
    printf("輸入你要遞迴的\n河內塔數目_");
    int n;	//塔數 
    scanf("%d", &n);
    time = 10 ;
    left = 1, mid = 2 * (n + 1), right = mid + 2 * n + 1;
    len = 3 * (2 * n + 1);  
    width = n + 1;
    
    for (int i = 0; i <= width; i++){
        for (int j = 0, num = i; j <= len; j++){
			//畫出邊界 
            if (i == 0 || j == 0 || i == width || j == len){ 
                map[i][j] = '@';
            } 
            //畫出間隔 
            if ((i > 1 && i < width) && (j == mid - 1 || j == right - 1)){ 
                map[i][j] = '|';
            } 
            if (num && (i >= 1 && i <= width - 1) && j % 2 != 0 && j < mid){
                map[i][j] = -4 ;//替換字 
                map[i][j + 1] = -10; //替換字 
                num--;
            }
        }
    }
    
    gotoxy(0, 0); 
    
    for (int i = 0; i <= width; i++){
        for (int j = 0; j <= len; j++){
        	printf("%c", map[i][j]);
		}
        printf("\n");
    }
    return n;
}

void play(int x, int y){
    int turn_0, n = 0, i, j, k, tx, ty, flag = 0;
    
    if ((x == mid && y == right) || (x == left && y == mid) || (x == left && y == right))
        turn_0 = 0; //往右
    else if ((x == mid && y == left) || (x == right && y == left) || (x == right && y == mid))
        turn_0 = 1; //往左
    //目的地
    for (i = 1, j = y; i <= width; i++){ 
        if (map[i][j] != 0){
            tx = i - 1;
            ty = j;
            break;
        }
    }
    //出發點 
    for (i = 1, j = x; i <= width; i++){  
        if (map[i][j] != 0){
            break;
        }
    }
    
    while (1){
        while ((i != 1 || j != x) && (i != 1 || j != y) && (i != tx || j != ty)){
            if (turn_0 == 0)
                for (k = mid - 3; k >= 0; k--){
                    map[i + next[turn[turn_0][n]][0]][j + next[turn[turn_0][n]][1] + k] = map[i][j + k];
                    map[i][j + k] = 0;
                }
            else
                for (k = 0; k < mid - 2; k++){
                    map[i + next[turn[turn_0][n]][0]][j + next[turn[turn_0][n]][1] + k] = map[i][j + k];
                    map[i][j + k] = 0;
                }
            gotoxy(j, i);
            Sleep(time);
            for (k = 0; k < mid - 2; k++){
                printf(" ");
            }
            i = i + next[turn[turn_0][n]][0];
            j = j + next[turn[turn_0][n]][1];
            gotoxy(j, i);
            Sleep(time);
            for (k = 0; k < mid - 2; k++){
                printf("%c", map[i][j + k]);
            }
        }
        n++; //改方向;
        if (i == tx && j == ty)
            return;
        if (turn_0 == 0)
            for (k = mid - 3; k >= 0; k--){
                map[i + next[turn[turn_0][n]][0]][j + next[turn[turn_0][n]][1] + k] = map[i][j + k];
                map[i][j + k] = 0;
            }
        else
            for (k = 0; k < mid - 2; k++){
                map[i + next[turn[turn_0][n]][0]][j + next[turn[turn_0][n]][1] + k] = map[i][j + k];
                map[i][j + k] = 0;
            }
        gotoxy(j, i);
        for (k = 0; k < mid - 2; k++){
            printf(" ");//替代字 
        }
        Sleep(time);
        i = i + next[turn[turn_0][n]][0];
        j = j + next[turn[turn_0][n]][1];
        gotoxy(j, i);
        for (k = 0; k < mid - 2; k++)
            printf("%c", map[i][j + k]);
        Sleep(time);
    }
}

void move(int a, int b, int c, char a_rod, char b_rod, char c_rod, int n){
	//遞迴河內塔 
    if (n == 1){
    	//the latest hanoi move  
        gotoxy(0, width + 1);
        printf("from %c to %c", a_rod, c_rod);
        play(a, c);
        //hanoi_count
        hanoi_count++;
        gotoxy(0, width + 2);
        printf("move: %d times", hanoi_count);
        return;
    }
    //hanoi_move
    move(a, c, b, a_rod, c_rod, b_rod, n - 1);
    gotoxy(0, width + 1);
    printf("from %c to %c", a_rod, c_rod);
    play(a, c);
    move(b, a, c, b_rod, a_rod, c_rod, n - 1);
    //hanoi_count
    hanoi_count++;
    gotoxy(0, width + 2);
    printf("move: %d times", hanoi_count);
//    gotoxy(0, width + 1);
}

int main()
{
    int n = init();
    move(left, mid, right, 'a', 'b', 'c', n);
    return 0;
}
