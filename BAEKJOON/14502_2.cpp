#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};
int n, m;
int arr[10][10];
vector<point> v;
int result, total = -3;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int BFS(int tempT) {
	bool chk[10][10] = { false, };
	queue<point> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		chk[v[i].x][v[i].y] = true;
	}

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y; q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny] == true || arr[nx][ny] != 0) continue;
				chk[nx][ny] = true;
				q.push({ nx,ny });
				tempT--;
			}
		}
	}
	return tempT;
}

void choice(int x, int k) {
	if (x == 3) {
		result = max(result, BFS(total));
	}
	else {
		for (int i = k; i < n*m; i++) {
			int cx = i / m;
			int cy = i % m;
			if (arr[cx][cy] != 0) continue;
			arr[cx][cy] = 1;
			choice(x + 1, i + 1);
			arr[cx][cy] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) v.push_back({ i,j });
			else if (arr[i][j] == 0) total++;
		}
	}
	choice(0, 0);
	cout << result;
	return 0;
}