#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("balancing");
	int n, b;
	cin >> n >> b;
	pair<int, int> cows[n];
	int x_coords[n];
	int y_coords[n];
	int x, y;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		cows[i].first = x;
		x_coords[i] = x + 1;
		cows[i].second = y;
		y_coords[i] = y + 1;
	}
	
	int answer = 1000000000;
	
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int q1 = 0;
			int q2 = 0;
			int q3 = 0;
			int q4 = 0;
			for (int k=0; k<n; k++) {
				if ((x_coords[i] > cows[k].first) && (y_coords[j] > cows[k].second)) {
					q1++;
				} else if ((x_coords[i] < cows[k].first) && (y_coords[j] > cows[k].second)) {
					q2++;
				} else if ((x_coords[i] > cows[k].first) && (y_coords[j] < cows[k].second)) {
					q3++;
				} else {
					q4++;
				}
			}
			int values[4] = {q1, q2, q3, q4};
			int max_value = *max_element(values, values+4);
			answer = min(answer, max_value);
		}
	}
	
	cout << answer << endl;
	
	return 0;
}
