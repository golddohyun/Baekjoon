#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(const char* strs, const int str_len) {
    int start = 0;
    int end = str_len - 1;
    while (start < end) {
        if (strs[start] != strs[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    int capacity = 10; // 초기 버퍼 크기
    char* strs = malloc(capacity * sizeof(char));
    int len = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        strs[len++] = ch;
        if (len == capacity) {
            capacity *= 2; // 버퍼 크기를 두 배로 늘림
            strs = realloc(strs, capacity * sizeof(char));
        }
    }
    strs[len] = '\0'; // 문자열 종료

    printf("%d", is_palindrome(strs, len));
    free(strs); // 메모리 해제
    return 0;
}
