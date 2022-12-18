#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("outofplace");
	int n;
	cin >> n;
	vector<int> v;
	int last = -1;
	int x;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x != last) {
			v.push_back(x);
			last = x;
		}
	}
	
	int total_swaps = 0;
	int swaps = 1;
	while (swaps > 0) {
		swaps = 0;
		for (int j=0; j<v.size()-1; j++) {
			if (v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
				swaps++;
				total_swaps++;
			}
		}
	}
	
	cout << total_swaps << endl;
			
	return 0;
}
