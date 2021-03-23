#include <stdio.h>
#include <windows.h>
/*
3��e���� �A�i�H�h�� 

*len: ���סA�ѥ���k 
*width: �e�סA�ѤW��U  
*left: ����϶�
*mid: �����϶�
*right: �k��϶�
*time: ����ɶ� 
*/
int len, width, left, mid, right, time;

char map[80][100];

int next[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //�W0�U1��2�k3�F

int turn[2][3] = {{0, 3, 1},  //a -> b   b -> c a -> c  �W�k�U
                  {0, 2, 1}}; //b -> a  c -> b  c -> a	�W���U
                  
int hanoi_count = 0;//�p��h�B�X��: �����̤p2^n - 1 

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
/*
�e�X�h�B���� 

*/ 
int init(){
	
    printf("��J�A�n���j��\n�e����ƥ�_");
    int n;	//��� 
    scanf("%d", &n);
    time = 10 ;
    left = 1, mid = 2 * (n + 1), right = mid + 2 * n + 1;
    len = 3 * (2 * n + 1);  
    width = n + 1;
    
    for (int i = 0; i <= width; i++){
        for (int j = 0, num = i; j <= len; j++){
			//�e�X��� 
            if (i == 0 || j == 0 || i == width || j == len){ 
                map[i][j] = '@';
            } 
            //�e�X���j 
            if ((i > 1 && i < width) && (j == mid - 1 || j == right - 1)){ 
                map[i][j] = '|';
            } 
            if (num && (i >= 1 && i <= width - 1) && j % 2 != 0 && j < mid){
                map[i][j] = -4 ;//�����r 
                map[i][j + 1] = -10; //�����r 
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
        turn_0 = 0; //���k
    else if ((x == mid && y == left) || (x == right && y == left) || (x == right && y == mid))
        turn_0 = 1; //����
    //�ت��a
    for (i = 1, j = y; i <= width; i++){ 
        if (map[i][j] != 0){
            tx = i - 1;
            ty = j;
            break;
        }
    }
    //�X�o�I 
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
        n++; //���V;
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
            printf(" ");//���N�r 
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
	//���j�e���� 
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
