#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("sleepy");
	int n;
	cin >> n;
	int arr[n];
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	for (int i=n-2; i>-1; i--) {
		if (arr[i] > arr[i+1]) {
			cout << i+1 << endl;
			break;
		}
		
		if (i==0) {
			cout << i << endl;
		}
	}
		
	return 0;
}
