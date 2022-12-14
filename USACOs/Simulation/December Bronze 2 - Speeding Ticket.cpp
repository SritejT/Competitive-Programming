#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int speed_limit[101], speed[101];
	int n, m, x, y;
	cin >> n >> m;
	int counter = 0;
	while (n--) {
		cin >> x >> y;
		while (x--) {
			counter++;
			speed_limit[counter] = y;
		}
	}
	counter = 0;
	while (m--) {
		cin >> x >> y;
		while (x--) {
			counter++;
			speed[counter] = y;
		}
	}
	int max = speed[1]-speed_limit[1];
	for (int i=2; i<101; i++) {
		if (speed[i] - speed_limit[i] > max) {
			max = speed[i] - speed_limit[i];
		}
	}
	if (max < 0) {
		cout << 0 << endl;
	} else {
		cout << max << endl;
	}
				
	return 0;
}
