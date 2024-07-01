#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};
int n, m, result;
bool light[101][101];
bool flag[101][101]; //np에 넣을점 체크
vector<point> arr[101][101];
queue<point> np; //처음 들린 불켜진 곳

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void printAll() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (light[i][j]) result++;
		}
	}
}

void BFS() {
	bool chk[101][101] = { false, };
	int cnt = 1;
	queue<point> q;
	q.push({ 1,1 });
	chk[1][1] = true;

 	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n || chk[nx][ny] || !light[nx][ny]) continue;
			
			if (flag[nx][ny] == false) {
				flag[nx][ny] = true;
				np.push({ nx,ny });
			}

			chk[nx][ny] = true;
			cnt++;
			q.push({ nx,ny });
		}
	}
}

void TurnOn() {
	//불 킬수 있는 곳 키고
	while (np.empty() == false) {
		int cx = np.front().x;
		int cy = np.front().y; np.pop();
		for (int i = 0; i < arr[cx][cy].size(); i++) {
			int nx = arr[cx][cy][i].x;
			int ny = arr[cx][cy][i].y;
			if (light[nx][ny] == false) light[nx][ny] = true;
		}
	}
}

int main() {
	cin >> n >> m;
	while (m--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		arr[x][y].push_back({ a,b });
	}

	flag[1][1] = true;
	light[1][1] = true;
	np.push({ 1,1 });

	while (!np.empty()) {
		TurnOn();
		BFS();
	}
	printAll();
	cout << result;
	return 0;
}