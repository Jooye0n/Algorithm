#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};
int n, m;
int arr[1000][1000];
bool chk[1000][1000];
int h, w, sx, sy, ex, ey;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int BFS() {
	int result = 0;
	chk[sx][sy] = true;
	queue<point> q;
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
				if (nx < 0 || ny < 0 || nx > n-h || ny > m-w || chk[nx][ny]) continue;
				chk[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		result++;
	}

	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> h >> w >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				for (int x = i - (h - 1); x <= i; x++) {
					for (int y = j - (w - 1); y <= j; y++) {
						if (x < 0 || y < 0 || x >= n || y >= m || chk[x][y]) continue;
						chk[x][y] = true;
					}
				}
			}
		}
	}



	cout<<BFS();
	return 0;
}