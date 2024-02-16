#include <stdio.h>
#include <string.h>

int main(void) {
    int len, sum_n=0;
    scanf("%d", &len);
    char numStr[len+1];
    int numArray[len];
    scanf("%s", numStr);
    for (int i=0; i < len; i++){
        numArray[i] = numStr[i] - '0';
    }
    //print out converted array 
    for (int i=0; i < len; i++) {
        sum_n+=numArray[i];
    }
    printf("%d", sum_n);
    return 0;
}