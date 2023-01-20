import sys
sys.setrecursionlimit(10**6)

M, N = map(int, input().split())

graph = [list(map(int, list(input()))) for _ in range(M)]
# [[0, 1, 0, 1, 0, 1], 
#  [0, 1, 0, 0, 0, 0], 
#  [0, 1, 1, 1, 0, 1], 
#  [1, 0, 0, 0, 1, 1], 
#  [0, 0, 1, 0, 1, 1]]

directions = [(-1, 0), (1, 0), (0,-1), (0, 1)]


def dfs(row, col) : 
    # graph는 (M*N) 짜리 array임
    graph[row][col] =2
    for d1, d2 in directions : 
        nrow, ncol = row + d1, col + d2
        if (0 <= nrow < M) and (0 <= ncol < N) and graph[nrow][ncol] == 0 :
            dfs(nrow, ncol)
    
for i in range(N) :
    if graph[0][i] == 0 :
        dfs(0, i)

print("YES" if 2 in graph[-1] else "NO")