#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

bool cmp_pair(pair<int, int> p, pair<int, int> q) {
	return ((p.second - p.first) > (q.second - q.first));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("mountains");
	int n;
	cin >> n;
	pair<int, int> peaks[n];
	for (int i=0; i<n; i++) {
		cin >> peaks[i].first >> peaks[i].second;
	}
	sort(peaks, peaks+n, cmp_pair);
	
	int answer = 0;
	int max_right_bound = 0;
	
	for (int i=0; i<n; i++) {
		if ((peaks[i].first + peaks[i].second) > max_right_bound) {
			answer++;
			max_right_bound = peaks[i].first + peaks[i].second;
		}
	}
	
	cout << answer << endl;
	return 0;
}

