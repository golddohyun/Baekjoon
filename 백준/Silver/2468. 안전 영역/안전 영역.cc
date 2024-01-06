#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define X first
#define Y second
#define MN 101
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[MN][MN];
int visited[MN][MN];

int bfs_run(int n, queue<pair<int, int>>& Q, int height) {
    int cnt = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 1 || board[i][j] <= height) continue;
            visited[i][j] = 1;
            Q.push({i, j});
            cnt++;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] == 1 || board[nx][ny] <= height) continue;
                    visited[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    queue<pair<int, int>> Q;
    int maxHeight = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            maxHeight = max(maxHeight, board[i][j]);
        }
    }

    int maxsafenum = 0;

    for (int height = 0; height <= maxHeight; height++) {
        int tmp = bfs_run(n, Q, height);
        maxsafenum = max(maxsafenum, tmp);
    }
    cout << maxsafenum << endl;
}
