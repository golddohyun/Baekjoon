#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int cnt = 1;

void dfs(int t) {
    visited[t] = cnt;
    sort(graph[t].begin(), graph[t].end());
    for(int i: graph[t]) {
        if(visited[i] == 0) {
            cnt++;
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // For faster I/O
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    graph.resize(N+1);
    visited.resize(N+1, 0);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);  // bidirectional edge
        graph[b].push_back(a);  // bidirectional edge
    }

    dfs(R);

    for(int i = 1; i <= N; i++) {
        cout << visited[i] << "\n";
    }

    return 0;
}
