#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};

int n, m;
int result;
char arr[102][102];
string blank = "00000000000000000000000000"; //26개
string cur;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void BFS(point p) {
	map<string, bool> mm[102][102];
	queue<point> q;
	q.push(p);
	mm[p.x][p.y][cur] = true;

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx > n+1 || ny > m+1 || arr[nx][ny] == '*') continue;

			if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
				cur[arr[nx][ny] - 'a'] = '1';
			}
			else if (arr[nx][ny] == '$') {
				result++;
				arr[nx][ny] = '.';
			}
			else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') {
				int idx = arr[nx][ny] - 'A';
				if (cur[idx] == '0') continue;
			}

			if (mm[nx][ny].count(cur) > 0) continue;
			mm[nx][ny][cur] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;

		/* init */
		result = 0;
		cur = blank;

		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				if (i > 0 && i < n + 1 && j > 0 && j < m + 1) continue;
				arr[i][j] = '.';
			}
		}
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			for (int j = 1; j <= m; j++) {
				arr[i][j] = s[j - 1];
			}
		}

		string temp; cin >> temp;
		if (temp.compare("0") != 0){
			for (int i = 0; i < temp.size(); i++) cur[temp[i] - 'a'] = '1';
		}

		BFS({ 0,0 });
		cout << result << '\n';
	}
	return 0;
}