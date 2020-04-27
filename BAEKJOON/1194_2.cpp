#include <cstdio>
#include <iostream>
#include <string> 
#include <queue>

using namespace std;
struct point {
	int x, y;
	string s;
};
int n, m;
char arr[50][50];
bool chk[50][50][64];

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
const int bin[6] = { 1,2,4,8,16,32 };

int getIdx(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') res += bin[i];
	}
	return res;
}

int BFS(int x, int y) {
	int result = 0;
	chk[x][y][0] = true;
	queue<point> q;
	q.push({ x,y,"000000" });

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y;
			string cstr(q.front().s); q.pop();
			if (arr[cx][cy] == '1') return result;
			int cidx = getIdx(cstr);

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '#') continue;

				int nidx = cidx;
				string nstr = cstr;

				if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f') {
					int idx = arr[nx][ny] - 'a';
					if (cstr[idx] == '0') {
						nidx += bin[idx];
						nstr[idx] = '1';
					}
				}
				else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') {
					int idx = arr[nx][ny] - 'A';
					if (cstr[idx] == '0') continue;
				}

				if (chk[nx][ny][nidx] == true) continue;
				chk[nx][ny][nidx] = true;
				q.push({ nx,ny,nstr });
			}

		}
		result++;
	}

	return -1;
}

int main() {
	int sx, sy;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == '0') {
				sx = i; sy = j;
				arr[i][j] = '.';
			}
		}
	}

	cout<<BFS(sx, sy);
	return 0;
}