#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int pos[15];
int n;

bool chk(int queen, int rowpos) {
	for (int i = 0; i < queen; i++) {
		int rowpos2 = pos[i];
		if (rowpos2 == rowpos || rowpos2 == rowpos - (queen - i) || rowpos2 == rowpos + (queen - i)) return false;
	}
	return true;
}

void recur(int x) {
	if (x == n) ++cnt;
	else {
		for (int i = 0; i < n; i++) {
			if (chk(x, i)) {
				pos[x] = i;
				recur(x + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	recur(0); printf("%d\n", cnt); return 0;
}