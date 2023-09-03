#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int cnt = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = cnt;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int nei : graph[v]) {
            if (visited[nei] == 0) {
                q.push(nei);
                cnt++;
                visited[nei] = cnt;
            }
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    graph.resize(N + 1);
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(R);

    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
