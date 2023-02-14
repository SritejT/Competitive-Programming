#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
bool vis[100001];

vector<vector<int> > connected_components;

vector<int> curr_connected;

void dfs(int node) {
	if (vis[node]) {
		return;
	}
	curr_connected.push_back(node);
	vis[node] = true;
	for (int i=0; i<graph[node].size(); i++) {
		dfs(graph[node][i]);
	}
}

int main() {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	pair<int, int> coords[n];
	
	for (int i=0; i<n; i++) {
		cin >> coords[i].first >> coords[i].second;
	}
	
	int x, y;
	for (int i=0; i<m; i++) {
		cin >> x >> y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}
	
	for (int i=0; i<n; i++) {
		if (!vis[i]) {
			curr_connected.clear();
			dfs(i);
			connected_components.push_back(curr_connected);
		}
	}
	
	long long min_p = 100000000000000;
	
	for (int i=0; i<connected_components.size(); i++) {
		int max_x = 0;
		int max_y = 0;
		int min_x = 100000000;
		int min_y = 100000000;
		for (int j=0; j<connected_components[i].size(); j++) {
			min_x = min(min_x, coords[connected_components[i][j]].first);
			max_x = max(max_x, coords[connected_components[i][j]].first);
			min_y = min(min_y, coords[connected_components[i][j]].second);
			max_y = max(max_y, coords[connected_components[i][j]].second);
		}
		
		long long p = 2 * (max_x - min_x + max_y - min_y);
		min_p = min(min_p, p);
	}
	
	cout << min_p;
}
