#include <stdio.h>
#include <string.h>

const int ALPHABET_COUNT = 26;

int initialize(int positions[]) {
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        positions[i] = -1;
    }
    return 0;
}

void savePosition(int* positions, char* S) {
    int len = strlen(S);
    for (int i = 0; i < len; i++) {
        char ch = S[i];
        if (ch >= 'a' && ch <= 'z') {
            int idx = ch - 'a';
            if (positions[idx] == -1) {
                positions[idx] = i; 
            }
        }
    }
}

int main() {
    char s[100];
    int l;
    int position[ALPHABET_COUNT];
    initialize(position);

    scanf("%s", s);

    l = strlen(s);
    savePosition(position, s); 

    for (int i = 0; i < ALPHABET_COUNT; i++) {
        printf("%d ", position[i]);
    }
    
    return 0;
}
