#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct point {
	int x, y;
	int dir; //내 칸(파이프)에서 나갈 수있는 방향
};

char arr[25][25];
bool chk[25][25];
char oper[7] = { '|','-','+','1','2','3','4'};
int n, m;

const int dx[4] = {1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };

point ans = { -1,-1,-1 }; //정답 저장용

int getNextDir(int dir, char cur) {
	if (cur == '1') {
		if (dir == 0 || dir == 2) return -1;
		return (dir + 1) % 4;
	}
	else if (cur == '2') {
		if (dir == 1 || dir == 2) return -1;
		return (dir + 2) % 4;
	}
	else if (cur == '3') {
		if (dir == 1 || dir == 3) return -1;
		return (dir + 3) % 4;
	}
	else if (cur == '4') { 
		if (dir == 0 || dir == 3) return -1;
		return (dir + 2) % 4; 
	}
	else {
		if (cur == '|') {
			if (dir == 2 || dir == 3) return -1;
		}
		else if (cur == '-') {
			if (dir == 1 || dir == 0) return -1;
		}

		return dir;
	}
}

bool chkAll() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != '.' && arr[i][j] != 'M' && arr[i][j] != 'Z' && chk[i][j] == true) return false;
		}
	}
	return true;
}

bool BFS(int x, int y) {
	//ans에 빈곳 저장 
	//이미 저장된 경우는 가능성 return
	queue<point> q;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (arr[nx][ny] != '.' && getNextDir(i,arr[nx][ny]) != -1) {
			q.push({ x,y,i });
			break;
		}
	}

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; 
		int cdir = q.front().dir; q.pop();

		int nx = cx + dx[cdir];
		int ny = cy + dy[cdir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
		if (arr[nx][ny] == '.') {
			if (ans.dir == -1) {
				ans.dir = 1;
				ans.x = nx;
				ans.y = ny;
			}
			return false;
		}
		else if (arr[nx][ny] == 'Z' && chkAll()) return true;
		else if (arr[nx][ny] == 'M') return false;

		int nextDir = getNextDir(cdir, arr[nx][ny]);
		if (nextDir == -1) return false;
		q.push({ nx,ny,nextDir });
		chk[nx][ny] = false;
	}
}

int main() {
	point sp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'M') {
				sp.x = i;
				sp.y = j;
			}
			if (arr[i][j] != '.' && arr[i][j] != 'M' && arr[i][j] != 'Z') chk[i][j] = true;
		}
	}

	BFS(sp.x, sp.y);
	for (int i = 0; i < 7; i++) {
		arr[ans.x][ans.y] = oper[i];
		if (BFS(sp.x, sp.y)) {
			cout << ans.x + 1 << ' ' << ans.y + 1 << ' ' << oper[i];
			return 0;
		}
	}
	return 0;
}