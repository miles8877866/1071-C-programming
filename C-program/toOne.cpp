#include <stdio.h> 
#include <stdlib.h> 

int main(void) { 
    int arr1[3][4] = {{1, 2, 3, 4}, 
                     {5, 6, 7, 8}, 
                     {9, 10, 11, 12}}; 
    int arr2[12] = {0}; 
    int row, column, i; 

    printf("原二維資料：\n"); 
    for(row = 0; row < 3; row++) { 
        for(column = 0; column < 4; column++) { 
            printf("%4d", arr1[row][column]); 
        } 
        printf("\n"); 
    } 

    printf("\n以列為主："); 
    for(row = 0; row < 3; row++) { 
        for(column = 0; column < 4; column++) { 
            i = column + row * 4; 
            arr2[i] = arr1[row][column]; 
        } 
    } 
    for(i = 0; i < 12; i++) 
        printf("%d ", arr2[i]); 

    printf("\n以行為主："); 
    for(row = 0; row < 3; row++) { 
        for(column = 0; column < 4; column++) { 
            i = row + column * 3; 
            arr2[i] = arr1[row][column]; 
        } 
    } 
    for(i = 0; i < 12; i++) 
        printf("%d ", arr2[i]); 

    printf("\n"); 

    return 0; 
} 
