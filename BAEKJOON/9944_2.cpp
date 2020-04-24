#include <bits/stdc++.h>
#define MAX 987987987

using namespace std;
struct point {
	int x, y;
};
int n, m, result;
char arr[30][30];
bool chk[30][30];

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };

void DFS(int x, int y, int blank, int dir, int cnt) {

	if (blank == 0) {
		result = min(result, cnt);
		return;
	}

	bool temp[30][30];
	memcpy(temp, chk, sizeof(chk));

	for (int i = 0; i < 4; i++) {
		if (i == dir) continue;
		int cx = x;
		int cy = y;
		int sub = blank;
		while (true) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny] == true || arr[nx][ny] == '*') break;
			cx = nx;
			cy = ny;
			chk[cx][cy] = true;
			sub--;
		}
		if (sub == blank) continue;
		DFS(cx, cy, sub, i, cnt + 1);
		memcpy(chk, temp, sizeof(chk));
	}
}

int main() {
	int t = 0;
	while (cin >> n >> m) {

		/*init*/
		int blank = 0;
		result = MAX;
		memset(chk, false, sizeof(chk));

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				arr[i][j] = s[j];
				if (arr[i][j] == '.') blank++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '.') {
					memset(chk, false, sizeof(chk));
					chk[i][j] = true;
					DFS(i, j, blank-1, -1, 0);
				}
			}
		}
		t++;
		if (result == MAX) printf("Case %d: -1\n", t);
		else printf("Case %d: %d\n", t, result);
	}
	return 0;
}