#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int n, m;
char arr[20][20];
bool chk[40]; //arr[x][y] - 'A'
int result = 0;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void DFS(int x, int y, int cnt) {
	if (result < cnt) result = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (chk[arr[nx][ny] - 'A'] == true) continue;
		chk[arr[nx][ny] - 'A'] = true;
		DFS(nx, ny, cnt+1);
		chk[arr[nx][ny] - 'A'] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}

	chk[arr[0][0] - 'A'] = true;
	DFS(0, 0,1);
	cout << result;
	return 0;
}