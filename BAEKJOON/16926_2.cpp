#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int arr[300][300];

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

void turnArr(int x) {
	int cx = x;
	int cy = x;
	int cnt = 0;
	int dir = 1;
	int temp = arr[cx][cy];

	while (cnt < 4) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];

		if (nx < x || ny < x || nx >= n - x || ny >= m - x) {
			dir = (dir + 1) % 4;
			cnt++;
		}
		else {
			arr[cx][cy] = arr[nx][ny];
			cx = nx;
			cy = ny;
		}
	}

	arr[x+1][x] = temp;
}

void printAll() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}cout << '\n';
	}
}

int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (r--) {
		for (int i = 0; i < min(n, m) / 2; i++) {
			turnArr(i);
		}
	}
	printAll();
	return 0;
}