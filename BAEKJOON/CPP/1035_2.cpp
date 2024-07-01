#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};
char arr[5][5];
bool chk[5][5];
int n = 5;
int result = 987987987;
vector<point> v; //조각들 모아두는 벡터

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int getDist(int x, int y, int x1, int y1) {
	return abs(x - x1) + abs(y - y1);
}

int testAll(int x, int y) {
	//연결 여부 확인. 전부 연결된 경우 true return
	int result = 1;
	chk[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || chk[nx][ny] == true || arr[nx][ny] == '.') continue;
		result += testAll(nx, ny);
	}

	return result;
}

void DFS(int x, int cnt) {
	if (x == v.size()) {
		memset(chk, false, sizeof(chk));
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (arr[x][y] == '*') {
					if (testAll(x, y) != (int) v.size()) return;
					else if (result > cnt) {
						result = cnt;
						return;
					}
				}
			}
		}
	}
	else {
		int cx = v[x].x;
		int cy = v[x].y;
		for (int i = 0; i < 25; i++) {
			int nx = i / 5;
			int ny = i % 5;

			if (arr[nx][ny] == '*') continue;

			arr[nx][ny] = '*';
			DFS(x + 1, cnt + getDist(nx,ny,cx,cy));
			arr[nx][ny] = '.';
		}
	}
}

int main() {
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == '*') {
				v.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	}
	DFS(0, 0);
	cout << result;
	return 0;
}