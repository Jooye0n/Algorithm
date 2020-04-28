#include <bits/stdc++.h>
using namespace std;
struct point {
	int x=0, y=0, dir=0;
};
int n;
char arr[50][50];
bool chk[50][50][2];

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

point B, E;

bool chkTree(int x, int y, int td, int dir) {
	if (td == 1) {
		if (dir == 0) {
			if (y + 1 >= n || arr[x][y + 1] == '1' || arr[x - 1][y + 1] == '1' || arr[x + 1][y + 1] == '1') return false;
			else return true;
		}
		else if (dir == 1) {
			if (y - 1 < 0 || arr[x][y - 1] == '1' || arr[x - 1][y - 1] == '1' || arr[x + 1][y - 1] == '1') return false;
			else return true;
		}
		else if (dir == 2) {
			if (x + 2 >=n || arr[x + 2][y] == '1') return false;
			else return true;
		}
		else if (dir == 3){
			if (x-2 < 0 || arr[x-2][y] == '1') return false;
			else return true;
		}
	}
	else {
		if (dir == 0) {
			if (y + 2 >=n || arr[x][y+2] == '1') return false;
			else return true;
		}
		else if (dir == 1) {
			if (y - 2 < 0 || arr[x][y-2] == '1') return false;
			else return true;
		}
		else if (dir == 2) {
			if (x + 1 >= n || arr[x+1][y] == '1' || arr[x+ 1][y - 1] == '1' || arr[x + 1][y + 1] == '1') return false;
			else return true;
		}
		else if (dir == 3) {
			if (x - 1 < 0 || arr[x-1][y] == '1' || arr[x - 1][y - 1] == '1' || arr[x - 1][y+ 1] == '1') return false;
			else return true;
		}
	}
}

bool chkTurn(int cx, int cy) {
	for (int i = cx - 1; i <= cx + 1; i++) {//회전
		for (int j = cy - 1; j <= cy + 1; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n) return false;
			if (arr[i][j] == '1') return false;
		}
	}
	return true;
}

int BFS() {
	int result = 0;
	queue<point> q;
	chk[B.x][B.y][B.dir] = true;
	q.push(B);

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cdir = q.front().dir; q.pop();
			if (cx == E.x && cy == E.y && cdir == E.dir) return result;

			for (int i = 0; i < 4; i++) { //4방향 이동
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (chkTree(cx, cy, cdir, i) == true && chk[nx][ny][cdir] == false) {
					chk[nx][ny][cdir] = true;
					q.push({ nx,ny,cdir });
				}
			}

			int ndir = cdir == 0 ? 1 : 0;
			if (chkTurn(cx, cy) == true && chk[cx][cy][ndir] == false) { //회전
				chk[cx][cy][ndir] = true;
				q.push({ cx,cy,ndir });
			}
		}
		result++;
	}
	

	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'B') {
				B.x = i;
				B.y = j;
			}
			else if (arr[i][j] == 'E') {
				E.x = i;
				E.y = j;
			}
		}
	}

	if (B.x - 1 >= 0 && arr[B.x - 1][B.y] == 'B') {
		B.x--;
		B.dir = 1;
	}
	else B.y--;

	if (E.x - 1 >= 0 && arr[E.x - 1][E.y] == 'E') {
		E.x--;
		E.dir = 1;
	}
	else E.y--;

	cout<<BFS();
	return 0;
}