#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}


int main() {
	setIO("cowqueue");
	int n;
	cin >> n;
	pair<int, int> arrivals[n];
	for (int i=0; i<n; i++) {
		cin >> arrivals[i].first >> arrivals[i].second;
	}
	sort(arrivals, arrivals + n);
	int total = arrivals[0].first + arrivals[0].second;
	if (n > 1) {
		for (int i=1; i<n; i++) {
			if (total < arrivals[i].first) {
				total = arrivals[i].first + arrivals[i].second;
			} else {
				total += arrivals[i].second;
			}
		}
	}
	cout << total << endl;
		
	return 0;
}
