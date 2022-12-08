#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int psums[1001][1001], n, k;
	cin >> n >> k;
	int a, b, c, d;
	while (n--) {
		cin >> a >> b >> c >> d;
		psums[a][b]++;
		psums[c][d]++;
		psums[a][d]--;
		psums[c][b]--;
	}
	int answer = 0;
	for (int i=1; i<1002; i++) {
		for (int j=1; j<1002; j++) {
			psums[i][j] += psums[i-1][j]+psums[i][j-1]-psums[i-1][j-1];
			if (psums[i][j] == k) {
				answer++;
			}
		}
	}
	cout << answer << endl;
	return 0;
}
