#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define X first
#define Y second
#define MN 101
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    char board[MN][MN];
    int visited[MN][MN] = {0};
    int visited_ab[MN][MN] = {0};
    queue <pair <int, int>> Q;
    int n;
    int cnt_norm=0;
    int cnt_ab=0;
    string input;
    cin >> n;

    // Normal Board
    for (int i=0; i < n; i++){
        cin >> input;
        for (int j=0; j<n; j++){
            board[i][j] = input[j];
        }
    }

    for (int i=0; i < n; i ++){
        for (int j=0; j <n; j++){
            if (visited[i][j]==1) continue;
            visited[i][j] =1; 
            Q.push({i,j});
            cnt_norm++;

            while (!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                char curcolor = board[cur.X][cur.Y];
                for (int dir=0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    // condition check
                    if (nx < 0 || nx >= n | ny < 0 || ny >=n) continue;
                    if (visited[nx][ny]==1 || board[nx][ny] != curcolor) continue;
                    visited[nx][ny] =1;
                    Q.push({nx, ny});
                    }
            }
        }
    }

    // Abnormal Board
    for (int i=0; i < n; i++){
        for (int j=0; j<n; j++){
            if (board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    for (int i=0; i < n; i ++){
        for (int j=0; j <n; j++){
            if (visited_ab[i][j]==1) continue;
            visited_ab[i][j] =1; 
            Q.push({i,j});
            cnt_ab++;

            while (!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                char curcolor = board[cur.X][cur.Y];
                for (int dir=0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    // condition check
                    if (nx < 0 || nx >= n | ny < 0 || ny >=n) continue;
                    if (visited_ab[nx][ny]==1 || board[nx][ny] != curcolor) continue;
                    visited_ab[nx][ny] =1;
                    Q.push({nx, ny});
                    }
            }
        }
    }


    cout << cnt_norm << ' ' << cnt_ab << endl;
}
