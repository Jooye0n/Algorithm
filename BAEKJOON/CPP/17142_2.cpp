#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
	int x, y;
};
int n, m, total, result = MAX;
int arr[50][50];
vector<point> v;
vector<int> cho;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void choice(int x, int k) {
	if (x == m) {
		queue<point> q;
		bool chk[50][50] = { false, };
		int cnt = 0;
		int ex = total;

		for (int i = 0; i < cho.size(); i++) {
			int idx = cho[i];
			q.push(v[idx]);
			chk[v[idx].x][v[idx].y] = true;
		}

		while (q.empty() == false) {
			int size = q.size();
			while (size--) {
				int cx = q.front().x;
				int cy = q.front().y; q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n || chk[nx][ny] || arr[nx][ny] == 1) continue;
					chk[nx][ny] = true;
					q.push({ nx,ny });
					if (arr[nx][ny] == 0) ex--;
				}
			}
			cnt++;
			if (ex == 0) {
				result = min(result, cnt);
				return;
			}
		}


	}
	else {
		for (int i = k; i < v.size(); i++) {
			cho.push_back(i);
			choice(x + 1, i + 1);
			cho.pop_back();
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back({ i,j });
			}
			else if (arr[i][j] == 0) {
				total++;
			}
		}
	}
	if (total == 0) {
		cout << 0;
		return 0;
	}

	choice(0, 0);
	result == MAX ? cout << -1 : cout << result;
	return 0;
}