#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};
int arr[50][50];
bool chk[50][50];
int n, L, R;
bool flag = false;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void BFS(int x, int y) {
	int total = arr[x][y];
	vector<point> v;
	v.push_back({ x,y });
	chk[x][y] = true;
	queue<point> q;
	q.push({ x,y });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int sub = abs(arr[cx][cy] - arr[nx][ny]);
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || chk[nx][ny] == true) continue;
			if (sub < L || sub > R) continue;
			chk[nx][ny] = true;
			q.push({ nx,ny });
			v.push_back({ nx,ny });
			total += arr[nx][ny];
		}
	}
	if (v.size() > 1) flag = true;
	int val = total / v.size();
	for (int i = 0; i < v.size(); i++) {
		arr[v[i].x][v[i].y] = val;
	}
}

int main() {
	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;

	while (true) {
		flag = false;
		memset(chk, false, sizeof(chk));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (chk[i][j] == false) {
					BFS(i, j);
				}
			}
		}
		if (flag == false) break;
		else ans++;
	}
	cout << ans;
	return 0;
}