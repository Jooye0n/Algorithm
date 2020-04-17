#include <bits/stdc++.h>
using namespace std;
vector<bool> v[4];
bool chk[4]; //톱니바퀴 chk

void turn(int num, int dir) {

	chk[num] = true;

	if (num != 3) {
		if (v[num][2] != v[num + 1][6] && chk[num + 1] == false) turn(num + 1, dir*-1);
	}
	if (num != 0) {
		if (v[num][6] != v[num - 1][2] && chk[num - 1] == false) turn(num - 1, dir*-1);
	}

	if (dir == 1) {//시계
		v[num].insert(v[num].begin(), v[num].back());
		v[num].pop_back();
	}
	else { //반시계
		v[num].push_back(v[num].front());
		v[num].erase(v[num].begin());
	}
}


int main() {
	for (int i = 0; i < 4; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			v[i].push_back(s[j] - '0');
		}
	}

	int k; cin >> k;
	while (k--) {
		memset(chk, false, sizeof(chk));
		int num, dir; cin >> num >> dir;
		turn(num-1, dir);
	}

	int score = 1;
	int result = 0;

	for (int i = 0; i < 4; i++) {
		if (v[i][0] == 1) result += score;
		score *= 2;
	}

	cout << result;
	return 0;
}