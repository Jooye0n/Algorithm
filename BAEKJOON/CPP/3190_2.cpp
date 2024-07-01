#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int n, k;

const int dx[4] = { 0,-1,0,1 };
const int dy[4] = { 1,0,-1,0 };

int timer = 1;
int cx = 1;
int cy = 1;
int dir = 0;
vector<pair<int, int> > snake;
queue<pair<int, int> > oper;

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		arr[x][y] = 1;
	}

	int cnt; cin >> cnt;
	while(cnt--){
		int x; char d; cin >> x >> d;
		oper.push(make_pair(x, d));
	}

	snake.push_back(make_pair(cx, cy));
	arr[cx][cy] = 2;

	while (true) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];

		if (nx <= 0 || ny <= 0 || nx > n || ny > n) break;
		if (arr[nx][ny] == 2) break;

		if (arr[nx][ny] == 0) {
			arr[snake.front().first][snake.front().second] = 0;
			snake.erase(snake.begin());
		}

		snake.push_back(make_pair(nx, ny));
		arr[nx][ny] = 2;

		if (oper.empty() == false && timer == oper.front().first) {
			char op = oper.front().second;
			if (op == 'L') dir = (dir + 1) % 4;
			else dir = (dir + 3) % 4;
			oper.pop();
		}

		timer++;
		cx = nx;
		cy = ny;
	}
	cout << timer;
	return 0;
}