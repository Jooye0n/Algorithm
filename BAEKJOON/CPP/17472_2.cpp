#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 987987987

using namespace std;
struct point {
	int x, y;
};
int n, m, result = 0, groupNum = 1;
int arr[10][10];
bool chk[10][10];
vector<point> group[10];
vector<pair<int, pair<int, int> > > v; //두 그룹 별 거리 저장
int parent[11] = { 0,1,2,3,4,5,6,7,8,9,10 }; //각 그룹 별 부모 저장

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void printAll() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}cout << '\n';
	}
}

void BFS(int x, int y) {
	queue<point> q;
	q.push({ x,y });
	chk[x][y] = true;
	arr[x][y] = groupNum;
	group[groupNum].push_back({ x,y });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (chk[nx][ny] == true || arr[nx][ny] == 0) continue;
			chk[nx][ny] = true;
			arr[nx][ny] = groupNum;
			group[groupNum].push_back({ nx,ny });
			q.push({ nx,ny });
		}
	}
}

void getDistance(int x, int y) {
	//x그룹과 y그룹 사이의 거리 return
	//중간에 다른 섬이 있거나 하여 구할 수 없는 경우 MAX return

	for (int i = 0; i < group[x].size(); i++) {
		int cx = group[x][i].x;
		int cy = group[x][i].y;
		int dir = 0;
		int dist = 0;

		while (dir < 4) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				cx = group[x][i].x; cy = group[x][i].y;
				dir++;
				dist = 0;
			}
			else if (arr[nx][ny] == x) {
				cx = nx; cy = ny;
				dist = 0;
			}
			else if (arr[nx][ny] == y) {
				if (dist > 1 && dist != MAX) v.push_back(make_pair(dist, make_pair(x, y)));
				cx = group[x][i].x; cy = group[x][i].y;
				dir++;
				dist = 0;
			}
			else if (arr[nx][ny] > 0) {
				cx = group[x][i].x; cy = group[x][i].y;
				dir++;
				dist = 0;
			}
			else if (arr[nx][ny] == 0) {
				dist++;
				cx = nx; cy = ny;
			}
		}
	}
}

void choiceTwo(int x, int k, point p) {
	if (x == 2) {
		getDistance(p.x, p.y);
	}
	else {
		for (int i = k; i < groupNum; i++) {
			if (x == 0) p.x = i;
			else if (x == 1) p.y = i;
			choiceTwo(x + 1, i + 1, p);
		}
	}
}

int getParent(int x) {
	if (x == parent[x]) return x;
	else return getParent(parent[x]);
}

bool allGroup() {
	for (int i = 2; i < groupNum; i++) {
		if (getParent(1) != getParent(i)) return false;
	}
	return true;
}

void unionGroup(int x, int y) {
	if (x < y) { //y가 부모인 것들 부모 x로 바꿈
		for (int i = 1; i < groupNum; i++) {
			if (parent[i] == y) parent[i] = x;
		}
	}
	else {
		for (int i = 1; i < groupNum; i++) {
			if (parent[i] == x) parent[i] = y;
		}
	}
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
			if (chk[i][j] == false && arr[i][j] == 1) {
				BFS(i, j);
				groupNum++;
			}
		}
	}
	//printAll();
	choiceTwo(0, 1, { 0,0 });
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {

		int x = v[i].second.first;
		int y = v[i].second.second;
		int dist = v[i].first;

		//printf("[%d, %d] : %d\n", x, y, dist);

		if (getParent(x) != getParent(y)) {
			unionGroup(getParent(x), getParent(y));
			result += dist;
		}
	}

	if (allGroup() == true) cout << result;
	else cout << -1;

	return 0;
}