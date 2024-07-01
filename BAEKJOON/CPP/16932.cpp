#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
struct point {
	int x;
	int y;
};

int n, m;
int arr[MAX][MAX];//그룹 번호 map
bool chk[MAX][MAX];//그룹 번호 메기기 중복 없애기 위함
int group[987987];//그룹 크기 저장
bool chkIdx[987987];//그룹 중복 체크
vector<point> v;//전체 0들을 저장
int groupNum;//전체 그룹의 개수
int maxResult;//최종 결과

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int makeGroup(int x, int y) {
	int groupSize = 1;
	queue<point> q;
	chk[x][y] = true;
	q.push({ x,y });
	arr[x][y] = groupNum;

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front().x;
			int cy = q.front().y; q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny] == true || arr[nx][ny] == 0) continue;
				arr[nx][ny] = groupNum;
				chk[nx][ny] = true;
				groupSize++;
				q.push({ nx,ny });
			}
		}
	}
	return groupSize;
}

void DFS(int cx, int cy, int x, int result) {

	if (x == 4) {
		if (maxResult < result) maxResult = result;
		return;
	}

	int nx = cx + dx[x];
	int ny = cy + dy[x];

	if (nx < 0 || ny < 0 || nx >= n || ny >= m || chkIdx[arr[nx][ny]] == true || arr[nx][ny] == 0) {//이미 합쳐진 그룹
		DFS(cx, cy, x + 1, result);
		return;
	}

	chkIdx[arr[nx][ny]] = true;
	DFS(cx, cy, x + 1, result + group[arr[nx][ny]]);
	chkIdx[arr[nx][ny]] = false;
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
				groupNum++;
				group[groupNum] = makeGroup(i, j);
			}
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int cx = v[i].x;
		int cy = v[i].y;
		DFS(cx, cy, 0, 1);
	}

	printf("%d", maxResult);
	return 0;
}