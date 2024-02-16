#include <stdio.h>
#include <string.h>
#define MAXLEN 1000001

int main() {
    int cnt =0;
    int len; 
    char strs[MAXLEN];
    scanf("%[^\n]", strs); 
    getchar(); 
    len = strlen(strs);

    if (len == 1 && strs[0] == ' ') {
        printf("0");
        return 0;
    }
 
    for (int i=0; i < len; i++) {
        if (i!= 0 && i!= (len-1) && strs[i] == ' ') {
            cnt+=1;
        }
    }
    printf("%d", cnt+1);

}