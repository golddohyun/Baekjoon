// #include <bits/stdc++.h>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <sstream> 
using namespace std;

int main(){

    int N;
    cin >> N;
    cin.ignore(); // 개행 문자 무시

    // initialize vectors
    vector<int> result(N+1, 0);
    vector<vector<int>> adj(N+1);
    vector<int> time(N+1, 0);
    vector<int> indegree(N+1, 0);
    queue<int> Q;



    for (int i = 1; i < N+1; ++i) {
        string line;
        getline(cin, line); 
        istringstream iss(line);

        int num, first;
        iss >> first; 
        time[i] = first;

        while (iss >> num && num != -1){ // 입력의 끝을 -1로 가정
            adj[num].push_back(i);
            indegree[i]++;
        }
    }


    for (int i=1; i < N+1; i++){
        if (!indegree[i]){
            Q.push(i);
            result[i] = time[i];
        }
    }

    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (auto nei : adj[cur]){
            if (result[nei] < result[cur]+time[nei]){
                result[nei] = result[cur]+time[nei];
            }
            if (!--indegree[nei]) Q.push(nei);
        }
    }
    for (int idx=1; idx < result.size(); idx++){
        cout << result[idx] << endl;
    }
        
    return 0;
}
