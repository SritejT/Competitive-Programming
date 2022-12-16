#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("planting");
	int n;
	cin >> n;
	vector<int> farm[n+1];
	int x, y;
	for (int j=0; j<n-1; j++) {
		cin >> x >> y;
		farm[y].push_back(x);
		farm[x].push_back(y);
	}
	int answer = 0;
	for (int i=1; i<n+1; i++) {
		if (farm[i].size() > answer) {
			answer = farm[i].size();
		}
	}
	cout << answer + 1 << endl;
	return 0;
}
