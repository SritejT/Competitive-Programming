#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("cownomics");
	int n, m;
	cin >> n >> m;
	char spotty[n][m];
	string genome;
	for (int i=0; i<n; i++) {
		cin >> genome;
		for (int j=0; j<m; j++) {
			spotty[i][j] = genome[j];
		}
	}
	
	char plain[n][m];
	for (int i=0; i<n; i++) {
		cin >> genome;
		for (int j=0; j<m; j++) {
			plain[i][j] = genome[j];
		}
	}
	
	vector<char> spotty_cow, plain_cow;
	int answer = 0;
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			spotty_cow.push_back(spotty[j][i]);
			plain_cow.push_back(plain[j][i]);
		}
		int count = 0;
		for (int k=0; k<spotty_cow.size(); k++) {
			for (int l=0; l<plain_cow.size(); l++) {
				if (spotty_cow[k] == plain_cow[l]) {
					continue;
				}
				count++;
			}
		}
		if (count == spotty_cow.size() * plain_cow.size()) {
			answer++;
		}
		plain_cow.erase(plain_cow.begin(), plain_cow.end());
		spotty_cow.erase(spotty_cow.begin(), spotty_cow.end());
	}
	cout << answer << endl;
	
	return 0;
}
