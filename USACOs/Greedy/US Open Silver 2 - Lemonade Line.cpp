#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}


void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("lemonade");
	int n;
	cin >> n;
	int arr[n];
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n, cmp);
	for (int i=0; i<n; i++) {
		if (arr[i] < i) {
			cout << i << endl;
			break;
		} else if (i == n-1) {
			cout << n << endl;
		}
	}
	return 0;
}
