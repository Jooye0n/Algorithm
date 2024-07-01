#include <bits/stdc++.h>
using namespace std;

struct point {
	int x;
	int y;
};

int n, m;
char arr[1000][1000];
int cnt[1000][1000];
queue<point> q;

const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int brokenCas() {
	//arr<=cnt 면 부서진다. (주변 8개의 cnt++)
	int result = 0;
	while (true) {
		vector<point> v;
		while (q.size()) {
			int nx = q.front().x;
			int ny = q.front().y; q.pop();
			if (arr[nx][ny] != '.') {
				arr[nx][ny] = '.';
				v.push_back({ nx,ny });
			}
		}

		if (v.size() == 0) break;
		for(int i=0; i<v.size(); i++){
			for (int d = 0; d < 8; d++) {
				int nx = v[i].x + dx[d];
				int ny = v[i].y + dy[d];
				cnt[nx][ny]++;
				if (arr[nx][ny] != '.' && arr[nx][ny] - '0' <= cnt[nx][ny]) q.push({ nx,ny });
			}
		}
		
		result++;
	}
	return result;
}

void writeCnt() {
	//주변의 . 개수 저장한다.
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arr[i][j] == '.' || arr[i][j] == 9) continue;

			for (int d = 0; d < 8; d++) {
				int cx = i + dx[d];
				int cy = j + dy[d];
				if (arr[cx][cy] == '.') cnt[i][j]++;
			}

			if (arr[i][j] - '0' <= cnt[i][j]) q.push({ i,j });
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) arr[i][j] = s[j];
	}
	writeCnt();
	cout << brokenCas();
	return 0;
}