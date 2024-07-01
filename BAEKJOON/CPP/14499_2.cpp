#include <bits/stdc++.h>
using namespace std;
int n, m, cx, cy, k;
int arr[20][20];
vector<int> dice1(4,0);
vector<int> dice2(4,0);
const int dx[5] = { 0,0,0,-1,1 };
const int dy[5] = { 0,1,-1,0,0 };

void moveDice(int dir) {
	if (dir == 1) {
		dice2.push_back(dice2.front());
		dice2.erase(dice2.begin());
	}
	else if (dir == 2) {
		dice2.insert(dice2.begin(), dice2.back());
		dice2.pop_back();
	}
	else if (dir == 3) {
		dice1.insert(dice1.begin(), dice1.back());
		dice1.pop_back();
	}
	else if (dir == 4) {
		dice1.push_back(dice1.front());
		dice1.erase(dice1.begin());
	}

	if (dir == 1 || dir == 2) {
		dice1[1] = dice2[1];
		dice1[3] = dice2[3];
	}
	else {
		dice2[1] = dice1[1];
		dice2[3] = dice1[3];
	}
}


int main() {
	cin >> n >> m >> cx >> cy >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (k--) {
		int dir; cin >> dir;
		//dir 방향으로 이동 후 상단 값 출력
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		moveDice(dir);

		if (arr[nx][ny] == 0) arr[nx][ny] = dice1[1];
		else {
			dice1[1] = arr[nx][ny];
			dice2[1] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		cout << dice1[3] << '\n';
		cx = nx;
		cy = ny;
	}

	return 0;
}