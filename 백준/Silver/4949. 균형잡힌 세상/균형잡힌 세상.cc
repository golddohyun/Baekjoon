#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        string input;
        getline(cin, input);
        if (input == ".") break;
        stack<int> ST;
        bool flg = 0;
        
        for (auto x : input) {
            if ((x == '(') || (x == '[')) ST.push(x);
            else if ((x == ')') || (x == ']')) {
                if (ST.empty()) {
                    flg = 1;
                    break;}
                else if ((x == ')') && (ST.top() == '(')) ST.pop();
                else if ((x == ']') && (ST.top() == '[')) ST.pop();
                else {
                    flg = 1;
                    break; }
            }
        }
        if (!ST.empty()) flg = 1;
        if (flg == 0) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}