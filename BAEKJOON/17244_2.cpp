#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
	bool found[6] = { false, };
	int things;
};

int n,m;
char arr[50][50];
bool chk[50][50][35];
point sp, ep;
int ans;
int match[6] = { 0,1,2,4,8,16 }; //이진수 변환을 위함

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void printAll() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}cout << '\n';
	}
}

int BFS() {
	int result = 0;
	queue<point> q;
	chk[sp.x][sp.y][0] = true;
	q.push(sp);

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y; 
			bool cfound[6];
			for (int i = 0; i < 6; i++) {
				cfound[i] = q.front().found[i]; //찾은 물건
			}
			int cthing = q.front().things; q.pop(); //match의 합
			if (cthing == ans && cx == ep.x && cy == ep.y) return result;

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '#'|| chk[nx][ny][cthing] == true) continue;

				if (arr[nx][ny] == '.') {
					
					chk[nx][ny][cthing] = true;
					point p; p.x = nx; p.y = ny; p.things = cthing;
					for (int i = 0; i < 6; i++) p.found[i] = cfound[i];
					q.push(p);
				}
				else { //물건
					int idx = arr[nx][ny] - '0'; //물건의 맵 번호
					
					if (cfound[idx] == false) { //물건 찾은적 없음
						chk[nx][ny][cthing + match[idx]] = true;
						point p; p.x = nx; p.y = ny; p.things = cthing + match[idx];
						for (int i = 0; i < 6; i++) p.found[i] = cfound[i];
						p.found[idx] = true;
						q.push(p);
					}
					else {//있음
						chk[nx][ny][cthing] = true;
						//q.push({ nx,ny,cfound[6],cthing });

						point p; p.x = nx; p.y = ny; p.things = cthing;
						for (int i = 0; i < 6; i++) p.found[i] = cfound[i];
						q.push(p);
					}
				}
			}
		}
		result++;
	}
}

void getAnswer(int idx) {
	for (int i = 1; i < idx; i++) {
		ans += match[i];
	}
}

int main() {
	cin >> m >> n;
	int idx = 1;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'X') {
				arr[i][j] = '0' + idx++;
			}
			else if (arr[i][j] == 'S') {
				sp.x = i; sp.y = j; 
				for (int i = 0; i < 6; i++) {
					sp.found[i] = false;
				}
				sp.things = 0;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'E') {
				ep.x = i; ep.y = j;
				arr[i][j] = '.';
			}
		}
	}

	getAnswer(idx);
	cout<<BFS();
	return 0;
}