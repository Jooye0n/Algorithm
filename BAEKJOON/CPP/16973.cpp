#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
struct point {
	int x, y;
};
int n, m, h, w, sx, sy, ex, ey;
int arr[MAX][MAX];
bool chk[MAX][MAX];

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int foundShort() {
	int result = 0;
	queue<point> q;
	chk[sx][sy] = true;
	q.push({ sx,sy });

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y; q.pop();
			if (cx == ex && cy == ey) return result;

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx <= 0 || ny <= 0 || nx > n-h+1 || ny > m-w+1 || chk[nx][ny] == true) continue;

				chk[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		result++;
	}
	return -1;
}

void chkRec(int x, int y) {
	chk[x][y] = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int cx = x - i;
			int cy = y - j;
			if (cx <= 0 || cy <= 0 || cx > n-h+1 || cy > m-w+1 || chk[cx][cy] == true) continue;
			chk[cx][cy] = true;
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> h >> w >> sx >> sy >> ex >> ey;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				chkRec(i, j);
			}
		}
	}

	cout << foundShort();
	return 0;
}