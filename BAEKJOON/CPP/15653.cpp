#include <bits/stdc++.h>
#define MAX 50
using namespace std;

struct point {
	int x;
	int y;
};

struct marvel {
	point red;
	point blue;
};

int n, m;
int minNum = MAX;
char arr[10][10];
bool chk[10][10][10][10][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

marvel moveArr(int dir, point red, point blue) {
	point newRed, nexBlue;
	int cx = red.x;
	int cy = red.y;
	bool flag = false;
	while (true) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
		if (arr[nx][ny] == '#') {
			if (flag == true) {
				newRed.x = cx - dx[dir];
				newRed.y = cy - dy[dir];
			}
			else {
				newRed.x = cx;
				newRed.y = cy;
			}
			break;
		}
		else if (arr[nx][ny] == 'O') {
			newRed.x = nx;
			newRed.y = ny;
			break;
		}
		if (nx == blue.x && ny == blue.y) {
			flag = true;
		}
		cx = nx; cy = ny;
	}

	cx = blue.x;
	cy = blue.y;
	flag = false;

	while (true) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
		if (arr[nx][ny] == '#') {
			if (flag == true) {
				nexBlue.x = cx - dx[dir];
				nexBlue.y = cy - dy[dir];
			}
			else {
				nexBlue.x = cx;
				nexBlue.y = cy;
			}
			break;
		}
		else if (arr[nx][ny] == 'O') {
			nexBlue.x = nx;
			nexBlue.y = ny;
			break;
		}
		if (nx == red.x && ny == red.y) {
			flag = true;
		}
		cx = nx; cy = ny;
	}
	return { newRed,nexBlue };
}

void DFS(int x, int dir, point red, point blue) {
	if (x == MAX) return;
	chk[red.x][red.y][blue.x][blue.y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (i == dir) continue;
		marvel mar = moveArr(i, red, blue);
		if (arr[mar.blue.x][mar.blue.y] == 'O') {//실패
			continue;
		}
		if (arr[mar.red.x][mar.red.y] == 'O') {//성공
			minNum = min(minNum, x);
			return;
		}
		if(chk[mar.red.x][mar.red.y][mar.blue.x][mar.blue.y][x+1] == false) DFS(x + 1, i, mar.red, mar.blue);
	}
}
int main() {
	point redP, blueP;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'R') {
				redP.x = i;
				redP.y = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				blueP.x = i;
				blueP.y = j;
				arr[i][j] = '.';
			}
		}
	}

	DFS(1, -1, redP, blueP);
	minNum == MAX ? cout << -1 : cout << minNum;
	return 0;
}