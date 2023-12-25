#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int maxlen = (int)'z'-'a'+1;
    int dct_arr[maxlen] = {0};
    string input;
    cin >> input;

    for (auto c : input){
        int tmp = c - 'a';
        dct_arr[tmp]++;
    }

    for (int i = 0; i < maxlen; ++i) {
        cout << dct_arr[i] << ' ';
    }

    return 0;
}