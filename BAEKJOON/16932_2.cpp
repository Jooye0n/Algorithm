#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
struct point {
	int x, y;
};
int n, m, result;
int arr[1000][1000];
int chk[1000][1000];
bool groupChk[MAX];
int group[MAX];
int num = 1;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int BFS(int x, int y) {
	int res = 1;
	chk[x][y] = num;
	queue<point> q;
	q.push({ x,y });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n | ny >= m || chk[nx][ny] != 0 || arr[nx][ny] == 0) continue;
			res++;
			chk[nx][ny] = num;
			q.push({ nx,ny });
		}
	}

	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && chk[i][j] == false) {
				group[num] = BFS(i, j);
				num++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) continue;
			int tempResult = 1;
			vector<int> gv;

			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny] == 0 || groupChk[chk[nx][ny]] == true) continue;
				gv.push_back(chk[nx][ny]);
				groupChk[chk[nx][ny]] = true;
				tempResult += group[chk[nx][ny]];
			}

			for (int i = 0; i < gv.size(); i++) {
				groupChk[gv[i]] = false;
			}

			result = max(result, tempResult);
		}
	}

	cout << result;
	return 0;
}