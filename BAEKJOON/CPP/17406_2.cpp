#include <bits/stdc++.h>
using namespace std;
struct Oper {
	int x, y, d;
};
int n, m, k, result = 987987987;
int arr[50][50];
int temp[50][50];
vector<Oper> oper;
int turn[7];//연산 순서
bool chk[7];//연산 중복 제거용

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int getTotal() {
	int tempResult = 987987987;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += arr[i][j];
		}
		tempResult = min(tempResult, cnt);
	}
	return tempResult;
}

void turnArr(int sx, int sy, int x, int y, int d) {
	int cnt = 0;
	int cx = x;
	int cy = y;
	int temp = arr[cx][cy];
	while(cnt < 4) {
		int nx = cx + dx[d];
		int ny = cy + dy[d];

		if (nx<x || ny<y || nx>sx + (sx - x) || ny>sy + (sy - y)) {
			d = (d + 1) % 4;
			cnt++;
		}
		else {
			arr[cx][cy] = arr[nx][ny];
			cx = nx;
			cy = ny;
		}
	}

	arr[x][y + 1] = temp;
}

void choice(int x) {
	if (x == oper.size()) {
		memcpy(arr, temp, sizeof(arr));
		for (int z = 0; z < x; z++) {
			int idx = turn[z];
			int cx = oper[idx].x;
			int cy = oper[idx].y;
			int cd = oper[idx].d;

			for (int i = cd; i > 0; i--) {
				turnArr(cx, cy, cx - i, cy - i, 0);
			}
		}
		result = min(result, getTotal());

	}
	else {
		for (int i = 0; i < oper.size(); i++) {
			if (chk[i] == false) {
				turn[x] = i;
				chk[i] = true;
				choice(x + 1);
				chk[i] = false;
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memcpy(temp, arr, sizeof(arr));

	while (k--) {
		int x, y, d; cin >> x >> y >> d;
		oper.push_back({ x-1,y-1,d });
	}
	
	choice(0);
	cout << result;
}#include <bits/stdc++.h>
using namespace std;
struct Oper {
	int x, y, d;
};
int n, m, k, result = 987987987;
int arr[50][50];
int temp[50][50];
vector<Oper> oper;
int turn[7];//연산 순서
bool chk[7];//연산 중복 제거용

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int getTotal() {
	int tempResult = 987987987;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += arr[i][j];
		}
		tempResult = min(tempResult, cnt);
	}
	return tempResult;
}

void turnArr(int sx, int sy, int x, int y, int d) {
	int cnt = 0;
	int cx = x;
	int cy = y;
	int temp = arr[cx][cy];
	while(cnt < 4) {
		int nx = cx + dx[d];
		int ny = cy + dy[d];

		if (nx<x || ny<y || nx>sx + (sx - x) || ny>sy + (sy - y)) {
			d = (d + 1) % 4;
			cnt++;
		}
		else {
			arr[cx][cy] = arr[nx][ny];
			cx = nx;
			cy = ny;
		}
	}

	arr[x][y + 1] = temp;
}

void choice(int x) {
	if (x == oper.size()) {
		memcpy(arr, temp, sizeof(arr));
		for (int z = 0; z < x; z++) {
			int idx = turn[z];
			int cx = oper[idx].x;
			int cy = oper[idx].y;
			int cd = oper[idx].d;

			for (int i = cd; i > 0; i--) {
				turnArr(cx, cy, cx - i, cy - i, 0);
			}
		}
		result = min(result, getTotal());

	}
	else {
		for (int i = 0; i < oper.size(); i++) {
			if (chk[i] == false) {
				turn[x] = i;
				chk[i] = true;
				choice(x + 1);
				chk[i] = false;
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memcpy(temp, arr, sizeof(arr));

	while (k--) {
		int x, y, d; cin >> x >> y >> d;
		oper.push_back({ x-1,y-1,d });
	}
	
	choice(0);
	cout << result;
}