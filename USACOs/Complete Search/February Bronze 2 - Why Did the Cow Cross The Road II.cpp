#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("circlecross");
	string points;
	cin >> points;
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	int answer = 0;
	for (int i=0; i<25; i++) {
		for (int j=i+1; j<26; j++) {
			int first_char, second_char;
			for (int k=0; k<52; k++) {
				if (points[k] == alphabet[i]) {
					first_char = k;
					break;
				}
			}
			for (int l=0; l<52; l++) {
				if (points[51-l] == alphabet[i]) {
					second_char = 51-l;
					break;
				}
			}
			if (second_char - first_char == 1) {
				break;
			} else {
				int count = 0;
				for (int m=first_char+1; m<second_char; m++) {
					if (points[m] == alphabet[j]) {
						count++;
					}
				}
				if (count == 1) {
					answer++;
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}
