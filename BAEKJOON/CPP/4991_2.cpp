#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>

#define MAX 987987987
using namespace std;

struct point {
	int x, y;
	int idx;
	bool flag[11] = { 0,};
};

char arr[20][20];
int n, m; //n=h, m=w
int ans;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
const int bin[11] = { 0,1,2,4,8,16,32,64,128,256,1024};

int BFS(int x, int y) {
	int result = 0;
	bool chk[20][20][2048] = { false, };
	queue<point> q;
	q.push({ x,y,0,{0,0,0,0,0,0,0,0,0,0,0 } });
	chk[x][y][0] = true;

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cidx = q.front().idx; 
			if (cidx == ans) return result;

			bool cflag[11];
			memcpy(cflag, q.front().flag, sizeof(cflag)); q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 'x') continue;

				if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'K') {
					int nidx = cflag[arr[nx][ny]-'A'] == true ? cidx : bin[arr[nx][ny]-'A'] + cidx;
					if (chk[nx][ny][nidx] == true) continue;
					bool nflag[11]; memcpy(nflag, cflag, sizeof(cflag));
					nflag[arr[nx][ny] - 'A'] = true;
					chk[nx][ny][nidx] = true;
					q.push({ nx,ny,nidx,{nflag[0],nflag[1],nflag[2],nflag[3],nflag[4],nflag[5],nflag[6],nflag[7],nflag[8],nflag[9],nflag[10],} });
				}
				else {
					if (chk[nx][ny][cidx] == true) continue;
					chk[nx][ny][cidx] = true;
					q.push({ nx,ny,cidx,{cflag[0],cflag[1],cflag[2],cflag[3],cflag[4],cflag[5],cflag[6],cflag[7],cflag[8],cflag[9],cflag[10],} });
				}
			}
		}
		result++;
	}

	return -1;
}

void getAnswer(int x) {
	for (int i = 0; i < x; i++) {
		ans += bin[i];
	}
}

void printAll() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}cout << '\n';
	}
}

int main() {
	while (true) {
		ans = 0;
		int num = 1;
		int sx, sy;
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				arr[i][j] = s[j];
				if (arr[i][j] == 'o') {
					sx = i; sy = j;
					arr[i][j] = '.';
				}
				else if (arr[i][j] == '*') {
					arr[i][j] = num + 'A';
					num++;
				}
			}
		}
		getAnswer(num);
		cout << BFS(sx, sy) << '\n';
	}
	return 0;
}