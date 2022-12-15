#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("shuffle");
	int n;
	cin >> n;
	int shuffling[n+1], ids[n+1], order[n+1];
	int a, id;
	for (int i=1; i<n+1; i++) {
		cin >> a;
		order[i] = i;
		shuffling[i] = a;
	}
	for (int j=1; j<n+1; j++) {
		cin >> id;
		ids[j] = id;
	}
	int new_order[n+1];
	for (int k=0; k<3; k++) {
		fill(new_order, new_order+(n+1), 0);
		for (int l=1; l<n+1; l++) {
			new_order[l] = order[shuffling[l]];
		}
		for (int p=0; p<n+1; p++) {
			order[p] = new_order[p];
		}
	}
	for (int m=1; m<n+1; m++) {
		cout << ids[new_order[m]] << endl;
	}
	
	return 0;
}
