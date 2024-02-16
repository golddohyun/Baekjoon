#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 1000001

int is_palindrome(const char* strs, const int str_len) {
    int start =0;
    int end = str_len-1;
    while (start < end) {
        if (strs[start]!= strs[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char strs[MAXLEN];
    scanf("%[^\n]", strs); 
    getchar(); 
    int len = strlen(strs);

    printf("%d", is_palindrome(strs, len));

}

