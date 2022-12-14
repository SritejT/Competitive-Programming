#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, g;
	cin >> n;
	int moves[n][3];
	for (int i=0; i<n; i++) {
		cin >> a >> b >> g;
		moves[i][0] = a;
		moves[i][1] = b;
		moves[i][2] = g;
	}
	int max = 0;
	for (int j=1; j<4; j++) {
		int score = 0;
		int shells[4] = {0, 0, 0, 0};
		shells[j] = 1;
		for (int k=0; k<n; k++) {
			int temp = shells[moves[k][0]];
			shells[moves[k][0]] = shells[moves[k][1]];
			shells[moves[k][1]] = temp;
			if (shells[moves[k][2]] == 1) {
				score++;
			}
		}
		if (score > max) {
			max = score;
		}
	}
	cout << max;
				
	return 0;
}




