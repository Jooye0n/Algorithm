#include <bits/stdc++.h>
using namespace std;
int n;
int cntAlph, result;
bool chk[10];
int equalAlph[40];
vector<string> v;//단어 모음
vector<int> alph;

int stoNum(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt *= 10;
		int idx = s[i] - 'A';
		cnt += equalAlph[idx];
	}
	return cnt;
}

int calcul() {
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		total += stoNum(v[i]);
	}
	return total;
}

void choice(int x) {
	if (x == cntAlph) {
		result = max(result, calcul());
	}
	else {
		for (int i = 9; i > 9 - cntAlph; i--) {
			if (chk[i] == false) {
				chk[i] = true;
				equalAlph[alph[x]] = i;
				choice(x + 1);
				chk[i] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
		for (int j = 0; j < s.size(); j++) {
			int idx = s[j] - 'A';
			alph.push_back(idx);
		}
	}

	sort(alph.begin(), alph.end());
	alph.erase(unique(alph.begin(), alph.end()), alph.end());
	cntAlph = alph.size();

	choice(0);
	cout << result;
	return 0;
}