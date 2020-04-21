#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
	int x, y;
	bool flag;
};
int arr[1000][1000];
bool chk[1000][1000][2];
int n, m;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int BFS() {
	int result = 1;
	queue<point> q;
	chk[0][0][0] = true;
	q.push({ 0,0,false });

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y;
			bool cflag = q.front().flag; q.pop();
			if (cx == n - 1 && cy == m - 1) return result;

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
				if (arr[nx][ny] == 0 && chk[nx][ny][cflag] == false) {
					chk[nx][ny][cflag] = true;
					q.push({ nx,ny,cflag });
				}
				else if(arr[nx][ny] == 1 && cflag == false && chk[nx][ny][1] == false){
					chk[nx][ny][1] = true;
					q.push({ nx,ny,true });
				}
			}
		}
		result++;
	}

	return -1;
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	cout<<BFS();
	return 0;
}