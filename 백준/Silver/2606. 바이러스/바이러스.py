"""
첫 번째 줄 : node의 개수
두 번째 줄 : 연결된 edge의 개수

1) 빈 그래프 : 경로를 저장하기 위한 2차원 리스트
2) edge 개수만큼의 간선을 입력받아 경로를 graph에 저장
graph 리스트 안에 각 노드가 연결된 다른 노드를 채워주는 형식
(다만 컴퓨터 번호가 1번부터 시작해서 0번째 공간은 비어있음)

3) visited : 다녀간 정점 (0 : unvisited, 1 : visited)
4) 들리지않은 정점이면 dfs()를 이용하여 다시 반복
"""

node = int(input())
edge = int(input())


graph = [[]*node for _ in range(node+1)]

for _ in range(edge) :
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

cnt = 0
visited = [0]*(node+1)

def dfs(start) :
    global cnt
    visited[start] = 1
    for i in graph[start] :
        if visited[i] ==0 :
            dfs(i)
            cnt +=1
dfs(1)
print(cnt)
