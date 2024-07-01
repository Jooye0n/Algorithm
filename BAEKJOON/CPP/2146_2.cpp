#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MAX 987987987
using namespace std;

struct point {
	int x, y;
};

bool chk[100][100];
int arr[100][100];
int n, result = MAX;
int groupNum = 1;
point piece[10000]; //섬마다 일부 point

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void printAll() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j]<<' ';
		}cout << '\n';
	}
}

int getShortcut(int x, int y) {
	int res = -1;
	memset(chk, false, sizeof(chk));
	int num = arr[x][y];
	queue<point> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == num) {
				q.push({ i,j });
				chk[i][j] = true;
			}
		}
	}

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y; q.pop();
			if (arr[cx][cy] != 0 && arr[cx][cy] != num) return res;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || chk[nx][ny]) continue;
				chk[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		res++;
	}
}

void BFS(int x, int y) {
	queue<point> q;
	chk[x][y] = true;
	q.push({ x,y });
	arr[x][y] = groupNum;

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == 0 || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			arr[nx][ny] = groupNum;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j] == false && arr[i][j] == 1) {
				piece[groupNum].x = i;
				piece[groupNum].y = j;
				BFS(i, j); groupNum++;
			}
		}
	}


	for (int i = 1; i < groupNum; i++) {
		result = min(result, getShortcut(piece[i].x, piece[i].y));
	}
	cout << result;
	return 0;
}