#include <bits/stdc++.h>
using namespace std;
int n, k;
int mh[20];
int kh[20];
int arr[10][10];
bool chk[10];//지우의 손동작 체크
bool result;

void choice(int mx, int kx, int jx, int mcnt, int kcnt, int jcnt, int ex) { //ex = 제외되는 사람
	if (mcnt >= k || kcnt >= k) return;
	if (jcnt >= k) {
		result = true;
		return;
	}

	if (ex == 0) {
		if (arr[kh[kx]][mh[mx]] == 2) choice(mx + 1, kx + 1, jx, mcnt, kcnt + 1, jcnt, 2);
		else choice(mx + 1, kx + 1, jx, mcnt + 1, kcnt, jcnt, 1);
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (chk[i] == false) {
				chk[i] = true;
				if (ex == 1) { //경희 제외
					if(arr[i][mh[mx]] == 2) choice(mx + 1, kx, jx + 1, mcnt, kcnt, jcnt + 1, 2);
					else choice(mx + 1, kx, jx + 1, mcnt + 1, kcnt, jcnt, 0);
				}
				else { //민호 제외
					if (arr[i][kh[kx]] == 2) choice(mx, kx + 1, jx + 1, mcnt, kcnt, jcnt + 1, 1);
					else choice(mx, kx + 1, jx + 1, mcnt, kcnt + 1, jcnt, 0);
				}
				chk[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 20; i++) {
		cin >> kh[i];
	}
	for (int i = 0; i < 20; i++) {
		cin >> mh[i];
	}

	choice(0,0,0,0,0,0,2);
	cout << result;
	return 0;
}