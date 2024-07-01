#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int n, m, T;
int arr[MAX][MAX];
int temp[MAX][MAX];//확산될 먼지 담는다.

const int dx[4] = { 0,-1,0,1 };
const int dy[4] = { 1,0,-1,0 };
vector<int> machine; //공기청정기의 x값

void printAll() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}cout << '\n';
	}
}

void spread() {
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == -1) continue;
					temp[nx][ny] += arr[i][j] / 5;
					cnt++;
				}
				temp[i][j] += arr[i][j] - (arr[i][j] / 5) * cnt;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1) continue;
			arr[i][j] = temp[i][j];
		}
	}
}

int countAll() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) result += arr[i][j];
		}
	}
	return result;
}

bool bound(int x, int y, int k) {
	if (y < 0 || y >= m) return false;

	if (k == 0) {
		if (x >= 0 && x <= machine[k] ) return true;
		else return false;
	}else {
		if (x >= machine[k] && x < n ) return true;
		else return false;
	}
}


void moveMachine(int x, int dir, int k) {
	int mx = machine[x];
	int my = 0;
	int cnt = 0;
	int cx = mx;
	int cy = my;


	while (cnt < 4) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];

		if (bound(nx,ny,x) == false) {
			dir = (dir + k) % 4;
			cnt++;
		}
		else {
			arr[cx][cy] = arr[nx][ny];
			cx = nx;
			cy = ny;
		}
	}

	arr[mx][my+1] = 0;
	arr[mx][my] = -1;
}


int main() {
	cin >> n >> m >> T;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				machine.push_back(i);
			}
		}
	}

	while (T--) {
		spread();
		moveMachine(0,1,3);
		moveMachine(1,3,1);
	}

	cout<<countAll();
	return 0;
}