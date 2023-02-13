#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}

vector<int> graph[3001];
bool vis[3001];

int nodes = 0;
int max_nodes = 0;

void dfs(int node) {
	if (vis[node]) {
		return;
	}
	nodes++;
	vis[node] = true;
	for (int i=0; i<graph[node].size(); i++) {
		dfs(graph[node][i]);
	}
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int n;
	cin >> n;
	pair<int, int> coords[n];
	int ranges[n];
	
	for (int i=0; i<n; i++) {
		cin >> coords[i].first >> coords[i].second >> ranges[i];
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j) {
				continue;
			}
			
			int x_diff = (coords[i].first - coords[j].first);
			int y_diff = (coords[i].second - coords[j].second);
			
			if ((x_diff * x_diff) + (y_diff * y_diff) <= (ranges[i] * ranges[i])) {
				graph[i].push_back(j);
			}
		}
	}
	
	
	for (int i=0; i<n; i++) {
		nodes = 0;
		fill(vis, vis+3001, false);
		dfs(i);
		if (max_nodes < nodes) {
			max_nodes = nodes;
		}
	}
	
	cout << max_nodes;
}
