#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M; cin>>N>>M;  // 도시, 버스
    vector<pair<int,int> > arr[N+1];    // {정점, 비용}
    bool visited[N+1];
    fill(visited,visited+N+1,false);
    
    for(int i=0;i<M;i++){
        int from, to, val;
        cin>> from >> to >> val; 
        arr[from].push_back(pair<int,int>(to,val));
    }
    
    int dist[N+1];              // 시작점에서 각 노드까지의 최단거리를 저장해주는 배열
    fill(dist,dist+N+1,INF);    // 모든 거리의 비용을 최대로 설정
    priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > qu;

    int start, end; cin>>start>>end;
    
    qu.push(pair<int,int>(0,start));    // starting point 
    dist[start]=0;    // dist initialization
    
    while(!qu.empty()){
        int cost = qu.top().first;    // 현재 탐색할 정점의 비용
        int here = qu.top().second;   // 현재 탐색할 정점의 번호
        qu.pop();
        if(!visited[here]){           // pass visited
            visited[here]=true;
            if(here==end) continue;   // pass end point
                
            for(int i=0; i<arr[here].size(); i++){  
                int next = arr[here][i].first;
                int nextCost = arr[here][i].second;
                
                if(dist[next] > dist[here] + nextCost){    
                    dist[next] = dist[here] + nextCost;
                    qu.push(pair<int,int>(dist[next],next));
                }
            }
        }
    }
    cout<<dist[end];
    return 0;
}