#include <bits/stdc++.h>
#define MAX 100
struct point {
	int x, y;
};
using namespace std;
int n, m;
vector<point> arr[MAX][MAX];
bool flag[MAX][MAX]; //불 켜짐 여부
bool chk[MAX][MAX]; //불켜기 진행 여부
queue<point> q; //새로 불이 켜진 방을 담는다.

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void BFS(int x, int y) {
	bool tempChk[MAX][MAX] = { false, };
	queue<point> temp;
	tempChk[x][y] = true;
	temp.push({ x,y });

	while (temp.empty() == false) {
		int size = temp.size();
		while (size--) {
			int cx = temp.front().x;
			int cy = temp.front().y; temp.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || tempChk[nx][ny] == true || flag[nx][ny] == false) continue;
				temp.push({ nx,ny });
				if (chk[nx][ny] == false) {
					chk[nx][ny] = true;
					q.push({ nx,ny });
				}
				tempChk[nx][ny] = true;
			}
		}
	}
}

int cntLight() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flag[i][j] == true) cnt++;
		}
	}
	return cnt;
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		arr[a-1][b-1].push_back({ c-1,d-1 });
	}

	q.push({ 0,0 });
	flag[0][0] = true; //불 켜져있다.
	chk[0][0] = true;

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();

		for (int i = 0; i < arr[cx][cy].size(); i++) {
			int nx = arr[cx][cy][i].x;
			int ny = arr[cx][cy][i].y;
			if (flag[nx][ny] == false) {
				flag[nx][ny] = true;
			}
		}
		BFS(cx, cy);
	}

	cout << cntLight();
	return 0;
}