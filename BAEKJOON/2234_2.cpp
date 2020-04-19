#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};

bool wall[16][4] = {
	{0,0,0,0},//0
	{0,0,1,0},//1
	{0,0,0,1},//2
	{0,0,1,1},//3
	{1,0,0,0},//4
	{1,0,1,0},//5
	{1,0,0,1},//6
	{1,0,1,1},//7
	{0,1,0,0},//8
	{0,1,1,0},//9
	{0,1,0,1},//10
	{0,1,1,1},//11
	{1,1,0,0},//12
	{1,1,1,0},//13
	{1,1,0,1},//14
	{1,1,1,1},//15
};

int n, m;
int arr[50][50];
int sizeOfRoom[2600];
int chk[50][50];
bool flag[50][50];

int room = 0;
int maxSize = 0;
int wallSize = 0;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };

int BFS(int x, int y) {
	int cnt = 1;
	queue<point> q;
	chk[x][y] = room;
	q.push({ x,y });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		int cdir = arr[cx][cy];
		for (int i = 0; i < 4; i++) {
			if (wall[cdir][i] == true) continue;
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny] > 0) continue;
			chk[nx][ny] = room;
			q.push({ nx,ny });
			cnt++;
		}
	}

	return cnt;
}

void merge(int x, int y) {
	queue<point> q;
	flag[x][y] = true;
	q.push({ x,y });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || flag[nx][ny] == true) continue;
			if (chk[nx][ny] != chk[cx][cy]) wallSize = max(wallSize, sizeOfRoom[chk[cx][cy]] + sizeOfRoom[chk[nx][ny]]);
			else {
				flag[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 0) {
				room++;
				int temp = BFS(i, j);
				maxSize = max(maxSize, temp);
				sizeOfRoom[room] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (flag[i][j] == false) {
				merge(i, j);
			}
		}
	}

	printf("%d\n%d\n%d", room, maxSize, wallSize);
	return 0;
}