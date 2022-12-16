#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("factory");
	int n;
	cin >> n;
	vector<int> tree[n+1];
	int x, y;
	for (int i=0; i<n-1; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
	}
	int zero_degree_count = 0;
	int zero_node;
	
	for (int i=1; i<n+1; i++) {
		if (tree[i].size() == 0) {
			zero_degree_count++;
			zero_node = i;
		}
	}
	if (zero_degree_count == 1) {
		cout << zero_node << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
