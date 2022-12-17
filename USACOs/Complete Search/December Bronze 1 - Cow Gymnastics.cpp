#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("gymnastics");
	int n, k;
	cin >> k >> n;
	int rankings[k][n];
	for (int i=0; i<k; i++) {
		for (int j=0; j<n; j++) {
			cin >> rankings[i][j];
		}
	}
	
	int answer = 0;
	
	for (int i=1; i<n+1; i++) {
		for (int j=1; j<n+1; j++) {
			if (i == j) {
				continue;
			}
			int count = 0;
			for (int l=0; l<k; l++) {
				for (int m=0; m<n; m++) {
					if (rankings[l][m] == j) {
						break;
					} else if (rankings[l][m] == i) {
						count++;
						break;
					}
				}
			}
			if (count == k) {
				answer++;
			}
		}
	}
	
	cout << answer << endl;
			
	return 0;
}
