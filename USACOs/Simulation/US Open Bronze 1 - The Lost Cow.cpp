#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("lostcow");
	int x, y;
	cin >> x >> y;
	int answer = 0;
	int powers[14] = {0, 0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
	
	if (x == y) {
		cout << 0 << endl;
	} else if (x < y) {
		int i = 1;
		while (x < y) {
			x += powers[i+1] - powers[i-1];
			answer += powers[i-1] + 2*powers[i] + powers[i+1];
			i += 2;
		}
		answer -= (x-y);
		cout << answer << endl;
	} else {
		int i = 2;
		while (x > y) {
			x -= (powers[i+1] - powers[i-1]);
			answer += powers[i-1] + 2*powers[i] + powers[i+1];
			i += 2;
		}
		answer -= (y-x);
		cout << answer << endl;
	}
	
	return 0;
}
