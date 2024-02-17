#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 1000001

int groupcheck(char* st) {
    int alphahash[27];
    memset(alphahash, -1, sizeof(alphahash));
    for (int cid=0; cid < strlen(st); cid++){
        int hash_id = st[cid] - 'a';
        if (alphahash[hash_id]>=0){
            alphahash[hash_id]++;
            if (alphahash[hash_id] != cid) {
                return 0;
            }
        }
        else {
            alphahash[hash_id] = cid;
        }
    }
    return 1;
}

int main(void) {
    int len, cnt=0;
    scanf("%d", &len);
    getchar();

    for (int i=0; i < len; i++) {
        char tmp[MAXLEN];
        scanf("%[^\n]", tmp);
        getchar();
        if (groupcheck(tmp)){ cnt++; }
    }
    printf("%d", cnt);

    return 0;
}
