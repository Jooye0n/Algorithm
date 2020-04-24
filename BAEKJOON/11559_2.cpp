#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
	int x, y;
};
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };

int n = 12, m= 6;
char arr[12][6];
bool chk[12][6];
bool flag; //연속 가능 여부
int result; //연속 횟수

void BFS(int x, int y) {
	//터질게 있으면 flag = true
	//터질 것들은 .로 변경

	vector<point> v; //점들 모아두고 4개 이상일 경우 터트릴 용도
	queue<point> q;
	q.push({ x,y });
	v.push_back({ x,y });
	chk[x][y] = true;

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny] == true || arr[nx][ny] != arr[cx][cy]) continue;
			v.push_back({ nx,ny });
			q.push({ nx,ny });
			chk[nx][ny] = true;
		}
	}

	if (v.size() >= 4) {
		flag = true;
		for (int i = 0; i < v.size(); i++) {
			arr[v[i].x][v[i].y] = '.';
		}
	}

}

void downPuyo() {
	//뿌요를 바닥이나 다른 블록까지 아래로 내린다.
	for (int i = 0; i < m; i++) {
		stack<char> s;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] != '.') {
				s.push(arr[j][i]);
				arr[j][i] = '.';
			}
		}
		if (s.empty()) continue;
		for (int j = n - 1; s.empty() == false ; j--) {
			arr[j][i] = s.top(); s.pop();
		}
	}
}

int main() {
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}

	while (true) {
		flag = false;
		memset(chk, false, sizeof(chk));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (chk[i][j] == false && arr[i][j] != '.') BFS(i, j);
			}
		}
		
		if (flag == false) break; //터진게 없음
		else {
			downPuyo();
			result++;
		}
	}

	cout << result;
	return 0;
}