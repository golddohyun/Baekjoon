#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();

    queue <int> Q;
    
    // push X, pop, size, front, back, empty
    while(n--) {
        string c;
        getline(cin, c);
        if (c[1] == 'u') {
            int x = stoi(c.substr(5));
            Q.push(x);
        }
        else if (c[1] == 'o') {
            if (Q.empty()) cout << -1 << '\n';
            else { cout << Q.front() << '\n'; 
            Q.pop();}
        }
        else if (c[0] == 's') cout << Q.size() << '\n';
        else if (c[0] == 'e') cout << (int)Q.empty() << '\n';
        else if (c[0] == 'f') {
            if (Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        }
        else if (c[0] == 'b') {
            if (Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        }
    }
    return 0;
}