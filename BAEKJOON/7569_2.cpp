#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y, z;
};
int n, m, h;
int arr[100][100][100];
bool chk[100][100][100];

const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,-1,1 };

queue<point> q;
int remain = 0;

int BFS() {
	int result = 0;
	while (q.empty() == false) {
		int size = q.size();
		result++;
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cz = q.front().z; q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nz = cz + dz[i];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
				if (arr[nx][ny][nz] !=0 || chk[nx][ny][nz] == true) continue;
				remain--;
				chk[nx][ny][nz] = true;
				q.push({ nx,ny,nz });
			}
			if (remain == 0) return result;
		}
	}
	return -1;
}

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[j][k][i];
				if (arr[j][k][i] == 1) {
					q.push({ j,k,i });
					chk[j][k][i] = true;
				}
				else if (arr[j][k][i] == 0) remain++;
			}
		}
	}

	if (remain == 0) cout << 0;
	else cout << BFS();

	return 0;
}