#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("herding");
	int array[3];
	int a, b, c;
	cin >> array[0] >> array[1] >> array[2];
	sort(array, array+3);
	a = array[0];
	b = array[1];
	c = array[2];
	int diff1 = abs(b-a);
	int diff2 = abs(c-b);
	if ((diff1 == 2) || (diff2 == 2)) {
		cout << 1 << endl;
	} else if ((diff1 == 1) && (diff2 == 1)) {
		cout << 0 << endl;
	} else {
		cout << 2 << endl;
	}
	cout << max(diff1, diff2) - 1 << endl;
	return 0;
}
