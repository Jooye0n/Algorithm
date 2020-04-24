#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
	int x, y,dir;
};
int n, m;
char arr[100][100];
int chk[100][100][4];
vector<point> CP;

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

void BFS() {
	queue<point> q;
	for (int i = 0; i < 4; i++) {
		chk[CP[0].x][CP[0].y][i] = 0;
		q.push({ CP[0].x,CP[0].y,i});
	}

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cdir = q.front().dir; q.pop();
		if (cx == CP[1].x && cy == CP[1].y) continue;

		for (int i = 0; i < 4; i++) {
			if (i == (cdir + 2) % 4) continue;
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '*') continue;

			if (i == cdir) {
				if (chk[nx][ny][i] <= chk[cx][cy][cdir]) continue;
				chk[nx][ny][i] = chk[cx][cy][cdir];
				q.push({ nx,ny,i, });
			}
			else {
				if (chk[nx][ny][i] <= chk[cx][cy][cdir] + 1) continue;
				chk[nx][ny][i] = chk[cx][cy][cdir] + 1;
				q.push({ nx,ny,i });
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'C') CP.push_back({ i,j });
			for (int d = 0; d < 4; d++) {
				chk[i][j][d] = MAX;
			}
		}
	}

	BFS();

	int result = MAX;
	for (int i = 0; i < 4; i++) {
		result = min(chk[CP[1].x][CP[1].y][i], result);
	}
	cout << result;
	return 0;
}