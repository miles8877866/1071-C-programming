#include <stdio.h> 
#include <stdlib.h>
#define ROW 3
#define COLUMN 4

void toOneByRow(int[][], int[]);
void toOneByColumn(int[][], int[]);
int indexByRow(int, int);
int indexByColumn(int, int);
void toOne(int[][COLUMN], int[], int (*)(int, int));

int main(void) { 
    int arr1[ROW][COLUMN] = {{1, 2, 3, 4}, 
                             {5, 6, 7, 8}, 
                             {9, 10, 11, 12}}; 
    int arr2[ROW * COLUMN] = {0}; 

    printf("原二維資料：\n"); 
    int row, column;
    for(row = 0; row < 3; row++) { 
        for(column = 0; column < 4; column++) { 
            printf("%4d", arr1[row][column]); 
        } 
        printf("\n"); 
    } 

    printf("\n以列為主："); 
    toOneByRow(arr1, arr2);
    int i;
    for(i = 0; i < 12; i++) 
        printf("%d ", arr2[i]); 

    printf("\n以行為主："); 
    toOneByColumn(arr1, arr2);
    for(i = 0; i < 12; i++) 
        printf("%d ", arr2[i]); 

    printf("\n"); 

    return 0; 
} 

void toOneByRow(int arr1[][COLUMN], int arr2[]) {
    toOne(arr1, arr2, indexByRow);
}

void toOneByColumn(int arr1[][COLUMN], int arr2[]) {
    toOne(arr1, arr2, indexByColumn);
}

int indexByRow(int row, int column) {
    return column + row * COLUMN;
}

int indexByColumn(int row, int column) {
    return row + column * ROW;
}

void toOne(int arr1[][COLUMN], int arr2[], int (*index)(int, int)) {
    int row, column;
    for(row = 0; row < ROW; row++) { 
        for(column = 0; column < COLUMN; column++) { 
            arr2[index(row, column)] = arr1[row][column]; 
        } 
    }    
}
