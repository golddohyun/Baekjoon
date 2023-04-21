#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<vector<int>> adj, ans;
vector<int> dfsn;
vector<bool> finished;
stack<int> s;
int n, e, cnt;
 
int dfs(int cur){
	dfsn[cur] = ++cnt;
	s.push(cur);
 
	int ret = dfsn[cur];
 
	for (int next : adj[cur]){
		if (dfsn[next] == 0)
			ret = min(ret, dfs(next));
		else if (!finished[next])
			ret = min(ret, dfsn[next]);
	}
 
	if (ret == dfsn[cur]) {
		vector<int> scc;
 
		while (1) {
			int val = s.top(); s.pop();
			scc.push_back(val);
			finished[val] = true;
			if (val == cur)
				break;}
		ans.push_back(scc);}
	return ret;
}
 
int main(){
	scanf("%d %d", &n, &e);
 
	adj.resize(n + 1);
	dfsn.resize(n + 1);
	finished.resize(n + 1);
 
	for (int i = 0; i < e; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from].push_back(to);
	}
 
	for (int i = 1; i <= n; ++i)
		if(dfsn[i] == 0)
		dfs(i);
 
	for (int i = 0; i < ans.size(); ++i)
		sort(ans[i].begin(), ans[i].end());
	sort(ans.begin(), ans.end());
 
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j)
			printf("%d ", ans[i][j]);
		printf("-1\n");
	}	
	return 0;}
