#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    int n, Case = 0;
    char str[205];
    int tmp;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", str);
        printf("Case %d: ", ++Case);
        tmp = 0;
        char ch;
        for(int i = 0; i<strlen(str); i++) {
            if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
                while(tmp)
                    printf("%c", ch), tmp--;
                	ch = toupper(str[i]);
            } else {
                tmp = tmp*10 + str[i] - 48;
            }
        }
        while(tmp)
            printf("%c", ch), tmp--;
            
      	printf("\n");
    }
    return 0;
}
