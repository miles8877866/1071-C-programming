#include <stdio.h>
 
int main() {
    long long int n;
    while (scanf("%d", &n)!=EOF){
        long long cnt = (1 + n) * (1 + n) / 4;
        printf("%d\n", ((cnt - 1) * 2 + 1) * 3 - 6);
    }
    return 0;
}
