#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
	int x, y, h;
	int num; //찾아야 하는 수
};
int n, result = MAX;
int arr[10][10];
int chk[10][10][3][103];
queue<point> q;
int ex, ey;

const int n_x[8] = { -2,-2,-1,-1,1,1,2,2 };
const int n_y[8] = { -1,1,-2,2,-2,2,-1,1 };

const int b_x[4] = { -1,-1,1,1 };
const int b_y[4] = { -1,1,-1,1 };

const int r_x[4] = { -1,1,0,0 };
const int r_y[4] = { 0,0,1,-1 };

void pushQueue(int cx, int cy, int nx, int ny, int h, int num) {
	if (arr[nx][ny] == num) {
		if (chk[nx][ny][h][num + 1] <= chk[cx][cy][h][num] + 1) return;
		chk[nx][ny][h][num + 1] = chk[cx][cy][h][num] + 1;
		q.push({ nx,ny,h,num + 1 });
	}
	else {
		if (chk[nx][ny][h][num] <= chk[cx][cy][h][num] + 1) return;
		chk[nx][ny][h][num] = chk[cx][cy][h][num] + 1;
		q.push({ nx,ny,h,num });
	}
}


void move(int cx, int cy, int h, int num) {
	if (h == 0) { //n
		for (int i = 0; i < 8; i++) {
			int nx = cx + n_x[i];
			int ny = cy + n_y[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			pushQueue(cx, cy, nx, ny, h, num);
		}
	}
	else if (h == 1) { //b 대각선
		for (int i = 0; i < 4; i++) {
			int x = cx;
			int y = cy;
			while (true) {
				int nx = x + b_x[i];
				int ny = y + b_y[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
				pushQueue(cx, cy, nx, ny, h, num);
				x = nx;
				y = ny;
			}
		}
	}
	else if (h == 2) { //r
		for (int i = 0; i < 4; i++) {
			int x = cx;
			int y = cy;
			while (true) {
				int nx = x + r_x[i];
				int ny = y + r_y[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
				pushQueue(cx, cy, nx, ny, h, num);
				x = nx;
				y = ny;
			}
		}
	}
}


void BFS(int x, int y) {

	for (int i = 0; i < 3; i++) {
		q.push({ x,y,i,2 });
		chk[x][y][i][2] = 0;
	}

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y;
			int ch = q.front().h;
			int cnum = q.front().num; q.pop(); 
			if (cnum == n * n + 1) continue;

			for (int j = 0; j < 3; j++) {
				if (ch == j) { //같은말 이동
					move(cx, cy, ch, cnum);
				}
				else {//말 바꿈 같은자리
					if (chk[cx][cy][j][cnum] > chk[cx][cy][ch][cnum] + 1) {
						chk[cx][cy][j][cnum] = chk[cx][cy][ch][cnum] + 1;
						q.push({ cx,cy,j,cnum });
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	int sx, sy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				for (int u = 0; u <= n * n + 2; u++) {
					chk[i][j][k][u] = MAX;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				sx = i; sy = j;
			}
			else if (arr[i][j] == n * n) {
				ex = i, ey = j;
			}
		}
	}

	BFS(sx, sy);

	for (int i = 0; i < 3; i++) {
		//cout << chk[ex][ey][i][n*n + 1] << ' ';
		result = min(result, chk[ex][ey][i][n*n + 1]);
	}
	cout << result;
	return 0;
}