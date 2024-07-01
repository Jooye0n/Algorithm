#include <bits/stdc++.h>
using namespace std;
string str[6]; //단어 모음
bool chk[6]; //단어 chk
string arr[3]; //단어 맵

bool chkAll() {
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		string s;
		for (int j = 0; j < 3; j++) {
			s += arr[j][i];
		}
		for (int j = 0; j < 6; j++) {
			if (chk[j] == false && str[j].compare(s)==0) {
				chk[j] = true;
				v.push_back(j);
				break;
			}
		}
	}

	if (v.size() == 3) return true;
	else {
		for (int i = 0; i < v.size(); i++) {
			chk[v[i]] = false;
		}
		return false;
	}
}

void choice(int x) {
	if (x == 3) {
		if (chkAll() == true) {
			for (int i = 0; i < 3; i++) {
				cout << arr[i] << '\n';
			}
			exit(0);
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			if (chk[i] == false) {
				arr[x] = str[i];
				chk[i] = true;
				choice(x + 1);
				chk[i] = false;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 6; i++) {
		cin >> str[i];
	}
	choice(0);
	cout << 0;
	return 0;
}
