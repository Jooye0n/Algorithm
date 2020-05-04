#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
int n;
int arr[20][20];
int num[20][20];
int d1, d2;
int result = MAX;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void writeGroup(int x, int y) {
	//구역 나눠서 num에 쓰기(1-5)
	for (int i = 0; i <= d1; i++) {
		int cx = x + i; int cy = y - i;
		if (cx >= 0 && cy >= 0 && cx < n && cy < n) num[cx][cy] = 5;
		cx = x + d2 + i; cy = y + d2 - i;
		if (cx >= 0 && cy >= 0 && cx < n && cy < n) num[cx][cy] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		int cx = x + i; int cy = y + i;
		if (cx >= 0 && cy >= 0 && cx < n && cy < n) num[cx][cy] = 5;
		cx = x + d1 + i; cy = y - d1 + i;
		if (cx >= 0 && cy >= 0 && cx < n && cy < n) num[cx][cy] = 5;
	}


	for (int i = x + 1; i < x + d1 + d2; i++) {
		bool flag = false;
		if (i < 0) continue;
		if (i >= n) break;
		for (int j = 0; j < n; j++) {
			if (num[i][j] == 0) {
				if (flag == true) num[i][j] = 5;
			}
			else if (num[i][j] == 5) {
				if (flag == true) break;
				else flag = true;
			}
		}
	}

	for (int i = 0; i < x + d1; i++) {
		for (int j = 0; j <= y; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n || num[i][j] == 5) break;
			num[i][j] = 1;
		}
	}

	for (int i = 0; i <= x + d2; i++) {
		for (int j = y + 1; j < n; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n) break;
			if (num[i][j] == 5) continue;
			num[i][j] = 2;
		}
	}

	for (int i = x + d1; i < n; i++) {
		for (int j = 0; j < y - d1 + d2; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n || num[i][j] == 5) break;
			num[i][j] = 3;
		}
	}

	for (int i = x + d2 + 1; i < n; i++) {
		for (int j = y - d1 + d2; j < n; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n) break;
			if (num[i][j] == 5) continue;
			num[i][j] = 4;
		}
	}
}

void countResult() {
	int total[6] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int idx = num[i][j];
			total[idx] += arr[i][j];
		}
	}
	if (total[1] == 0 || total[2] == 0 || total[3] == 0 || total[4] == 0 || total[5] == 0 || total[0] > 0) return;
	else result = min(result, *max_element(total + 1, total + 6) - *min_element(total + 1, total + 6));
}

void choiceD() {
	//d1, d2 정하기
	for (d1 = 1; d1 <= n - 2; d1++) {
		for (d2 = 1; d1 + d2 <= n - 1; d2++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					memset(num, 0, sizeof(num));
					writeGroup(x, y);
					countResult();
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	choiceD();
	cout << result;
	return 0;
}