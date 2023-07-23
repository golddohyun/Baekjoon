import sys
from collections import deque

sys.setrecursionlimit(1000000)
N = int(sys.stdin.readline())
graph = [list(sys.stdin.readline().rstrip()) for _ in range(N)]

def BFS(x,y, visited):
    q = deque()
    q.append((x,y))
    dx = [-1,0,1,0]
    dy = [0,1,0,-1]
    visited[x][y] = 1
    while q:
        x, y = q.popleft()
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if 0<=nx<N and 0<=ny<N and graph[nx][ny] == graph[x][y] and not visited[nx][ny]:
                visited[nx][ny] = 1
                q.append((nx,ny))

## 정상인 경우
vis = [[0] * N for _ in range(N)]
cnt = 0
for i in range(N):
    for j in range(N) :
        if not vis[i][j] :
            BFS(i,j, vis)
            cnt+=1


## 적록색약
for i in range(N) :
    for j in range(N) :
        if graph[i][j] =='G' :
            graph[i][j] = 'R'

vis2 = [[0]*N for _ in range(N)]
cnt1 = 0
for i in range(N):
    for j in range(N) :
        if not vis2[i][j] :
            BFS(i,j, vis2)
            cnt1+=1

print(cnt, cnt1)