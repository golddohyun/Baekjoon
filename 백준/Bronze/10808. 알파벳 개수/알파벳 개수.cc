#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;


int main() {
    string input;
    map<char, int> dct;

    cin >> input;

    for (char key = 'a'; key <= 'z'; ++key) {
        dct[key] = 0;
    }

    for (auto c : input){
        dct[c]++;
    }

    for (const auto& pair : dct) {
        cout << pair.second << ' ';
    }
    return 0;
}