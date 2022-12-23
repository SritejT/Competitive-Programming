#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}


bool cmp_y(pair<int, int> p, pair<int, int> q) {
	return p.second < q.second;
}


int main() {
	setIO("pairup");
	int n;
	cin >> n;
	pair<int, int> cows[n];
	for (int i=0; i<n; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows, cows+n, cmp_y);
	int m = 0;
	for (int i=0; i<n; i++) {
		m += cows[i].first;
	}
	int left = 0;
	int right = n-1;
	int answer = 0;
	while (left <= right) {
		int sub = min(cows[left].first, cows[right].first);
		if (left == right) {
			sub /= 2;
		}
		answer = max(answer, cows[left].second + cows[right].second);
		cows[left].first -= sub;
		cows[right].first -= sub;
		if (cows[left].first == 0) {
			left++;
		}
		if (cows[right].first == 0) {
			right--;
		}
	}
	cout << answer << endl;
		
	return 0;
}
