#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();

    int cnt = 0;
    while(n--) {
        string input;
        getline(cin, input);
        stack<char> ST;
        
        for (auto x : input) {
            if (ST.empty()) ST.push(x);
            else {
                if (x == ST.top()) ST.pop();
                else {ST.push(x);}
            }
        }
        if (ST.empty()) cnt++;
    }
    cout << cnt << endl;
    return 0;
}