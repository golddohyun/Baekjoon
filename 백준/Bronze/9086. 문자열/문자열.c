#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 1000001

int main() {
    int input_num;
    scanf("%d", &input_num);
    getchar();

    // length 2짜리 string (char array)를 input_num 개수만큼 할당하려 한다.
    char** start_end = (char**)malloc(sizeof(char*) * (input_num+1));
    for (int i=0; i < input_num; i++){
        start_end[i] = (char*)malloc(3);
    }

    for (int i=0; i < input_num; i++){
        char tmp[MAXLEN];
        start_end[i] = (char*)malloc(3);
        scanf("%[^\n]", tmp);
        getchar();
        if (strlen(tmp) != 1){
            start_end[i][0] = tmp[0];
            start_end[i][1] = tmp[strlen(tmp)-1];
        }
        else {
            start_end[i][0] = tmp[0];
            start_end[i][1] = tmp[0];
        }
        start_end[i][2] = '\0';
    }
    for (int i = 0; i < input_num; i++) {
        printf("%s\n", start_end[i]);
    }
    
    for (int i = 0; i < input_num; i++) {
        free(start_end[i]); 
    }
    free(start_end); 
    return 0;
}

