#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
#define MAX 987987987

using namespace std;
int n;
int person[11];
bool arr[11][11];
int numOfgroup;
bool group[11];
int result = MAX;
bool chk[11];

int chkConnect(int x, int * total) {
	//연결 여부 검사와 동시에 인구수 합 계산
	chk[x] = true;
	*total += person[x];
	int res = 1;

	for (int i = 1; i <= n; i++) {
		if (arr[x][i] && group[i] == group[x] && chk[i] == false) {
			res += chkConnect(i, total);
		}
	}

	return res;
}

void choice(int x, int k) {
	if (x == numOfgroup) {
		memset(chk, false, sizeof(chk));
		int res = 0;
		int total[2] = { 0,0 };

		for (int r = 0; r <=1; r++) {
			for (int i = 1; i <= n; i++) {
				if (group[i] == r) {
					res += chkConnect(i,&total[r]);
					break;
				}
			}
		}

		if (res == n) result = min(result, abs(total[0] - total[1]));

	}
	else {
		for (int i = k; i <= n; i++) {
			group[i] = true;
			choice(x + 1, i + 1);
			group[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> person[i];
	}

	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		while (num--) {
			int y; cin >> y;
			arr[i][y] = true;
			arr[y][i] = true;
		}
	}

	for (numOfgroup = 1; numOfgroup < n; numOfgroup++) {
		choice(0, 1);
	}
	result == MAX ? cout<<-1 : cout << result;
	return 0;
}