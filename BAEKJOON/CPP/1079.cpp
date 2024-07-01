#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
int n;
int myNum;
int power[17];//유죄수
bool dieChk[17];//사망시 true
int arr[17][17];
int result;

void changePower(int x, bool flag) {
	dieChk[x] = flag;
	if (flag) {
		for (int i = 0; i < n; i++) {
			if (dieChk[i] == true || i == x) continue;
			power[i] += arr[x][i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (dieChk[i] == true || i == x) continue;
			power[i] -= arr[x][i];
		}
	}
}

void DFS(int x, int mNum, int cNum) {
	if (cNum == 0 || mNum == 0) {
		if (x > result) result = x;
		return;
	}

	int totalN = mNum + cNum;
	if (totalN % 2 == 0) {//밤
		for (int i = 0; i < n; i++) {
			if (i == myNum) continue;
			if (dieChk[i] == true) continue;
			changePower(i,true);
			DFS(x + 1, mNum, cNum - 1);
			changePower(i,false);
		}
	}
	else {//낮
		int mPower = -1 * MAX;
		int idx = -1;

		for (int i = 0; i < n; i++) {
			if (dieChk[i] == true) continue;
			if (mPower < power[i]) {
				idx = i;
				mPower = power[i];
			}
		}
		dieChk[idx] = true;
		if(idx == myNum) DFS(x, mNum - 1, cNum);
		else DFS(x, mNum, cNum - 1);
		dieChk[idx] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> power[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> myNum;
	DFS(0, 1, n - 1);
	cout << result;
	return 0;
}