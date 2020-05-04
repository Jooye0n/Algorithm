#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};
int n, m, k,total;
char arr[100][100];
bool chk[100][100];
int stickX[100];

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void printAll() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}cout << '\n';
	}
}

int BFS(int x, int y) {
	//바닥에 붙어있는 미네랄 수 센다.
	int cnt = 1;
	chk[x][y] = true;
	queue<point> q;
	q.push({ x,y });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '.' || chk[nx][ny] ) continue;

			chk[nx][ny] = true;
			q.push({ nx,ny });
			cnt++;
		}
	}

	return cnt;
}

bool checkAll() {
	//전체가 바닥에 붙은 클러스터이고, 떠있는 조각 없으면 return false;
	int cnt = 0;
	memset(chk, false, sizeof(chk));

	for (int j = 0; j < m; j++) 
		if (chk[n - 1][j] == false && arr[n - 1][j] == 'x') cnt += BFS(n - 1, j);

	if (cnt == total) return false; //떨어진 조각이 없음
	else return true; //있음
}

void downCluster() {
	//chk안된 조각을 바닥이나 다른 클러스터 까지 내린다.
	vector<point> v;
	char temp[100][100]; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == false && arr[i][j] == 'x') {
				v.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	}

	memcpy(temp, arr, sizeof(arr));
	//cout << '\n';  printAll();
	while (true) {
		for (int i = 0; i < v.size(); i++) {
			v[i].x++;
			int cx = v[i].x;
			int cy = v[i].y;
			arr[cx][cy] = 'x';
		}

		for (int i = 0; i < v.size(); i++) {
			int cx = v[i].x + 1;
			int cy = v[i].y;
			if (cx == n || temp[cx][cy] == 'x') return;
		}
		memcpy(arr, temp, sizeof(arr));
	}
	//cout << '\n'; printAll();
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'x') total++;
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> stickX[i];
		stickX[i] = n - stickX[i];
	}

	bool turn = false;
	for (int i = 0; i < k; i++) {
		//막대기 던지는 턴
		int x = stickX[i];
		if (turn == false) { //->
			for (int j = 0; j < m; j++) {
				if (arr[x][j] == 'x') {
					arr[x][j] = '.';
					total--;
					if(checkAll() == true) downCluster();
					break;
				}
			}
		}
		else { // <-
			for (int j = m-1; j >=0; j--) {
				if (arr[x][j] == 'x') {
					arr[x][j] = '.';
					total--;
					if (checkAll() == true) downCluster();
					break;
				}
			}
		}

		turn = !turn;
	}

	printAll();
	return 0;
}