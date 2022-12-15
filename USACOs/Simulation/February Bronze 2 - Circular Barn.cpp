#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("cbarn");
	int n;
	cin >> n;
	int x;
	vector<int> rooms;
	while (n--) {
		cin >> x;
		rooms.push_back(x);
	}
	long long minimum = 1000000000000;
	for (int i=0; i<rooms.size(); i++) {
		long long total_distance = 0;
		for (int j=0; j<rooms.size(); j++) {
			if (j < i) {
				total_distance += (rooms.size() - abs(j-i)) * rooms[j];
			} else {
				total_distance += abs(j-i) * rooms[j];
			}
		}
		if (total_distance < minimum) {
			minimum = total_distance;
		}
	}
	cout << minimum << endl;
	return 0;
}
