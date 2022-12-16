#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("traffic");
	int n;
	cin >> n;
	int sensors[n][3];
	string sensor_type;
	int min_val, max_val;
	for (int i=0; i<n; i++) {
		cin >> sensor_type >> min_val >> max_val;
		if (sensor_type == "on") {
			sensors[i][0] = 1;
		} else if (sensor_type == "off") {
			sensors[i][0] = 2;
		} else {
			sensors[i][0] = 3;
		}
		sensors[i][1] = min_val;
		sensors[i][2] = max_val;
	}
	
	int max_none, min_none;
	
	for (int j=0; j<n; j++) {
		if (sensors[j][0] == 3) {
			min_none = j;
			break;
		}
	}
	for (int k=n-1; k>-1; k--) {
		if (sensors[k][0] == 3) {
			max_none = k;
			break;
		}
	}
	
	int start_min_val = sensors[max_none][1];
	int start_max_val = sensors[max_none][2];
	
	if (max_none == 0) {
		cout << start_min_val << " " << start_max_val << endl;
	} else {
		for (int m=max_none-1; m>-1; m--) {
			if (sensors[m][0] == 1) {
				start_min_val -= sensors[m][2];
				start_max_val -= sensors[m][1];
			} else if (sensors[m][0] == 2) {
				start_min_val += sensors[m][1];
				start_max_val += sensors[m][2];
			} else {
				start_min_val = max(start_min_val, sensors[m][1]);
				start_max_val = min(start_max_val, sensors[m][2]);
			}
		}
		cout << start_min_val << " " << start_max_val << endl;
	}
	
	int end_min_val = sensors[min_none][1];
	int end_max_val = sensors[min_none][2];
	
	if (min_none == n-1) {
		cout << end_min_val << " " << end_max_val << endl;
	} else {
		for (int l=min_none+1; l<n; l++) {
			if (sensors[l][0] == 1) {
				end_min_val += sensors[l][1];
				end_max_val += sensors[l][2];
			} else if (sensors[l][0] == 2) {
				end_min_val -= sensors[l][2];
				end_max_val -= sensors[l][1];
			} else {
				end_min_val = max(end_min_val, sensors[l][1]);
				end_max_val = min(end_max_val, sensors[l][2]);
			}
		}
		cout << end_min_val << " " << end_max_val << endl;
	}
	
	return 0;
}
