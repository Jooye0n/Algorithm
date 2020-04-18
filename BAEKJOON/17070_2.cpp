#include <bits/stdc++.h>
using namespace std;
struct pipe {
	int x;
	int y;
	int dir;
};

int n;
int arr[16][16];

int BFS() {
	int result = 0;
	queue<pipe> q;
	q.push({ 0,1,1 });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cdir = q.front().dir; q.pop();

		if (cx == n - 1 && cy == n - 1) result++;

		if (cdir != 2 && cy+1<n && arr[cx][cy+1] != 1) q.push({ cx,cy + 1,1 });
		if (cdir != 1 && cx+1<n && arr[cx+1][cy] != 1) q.push({ cx + 1,cy,2 });
		if (cx + 1 < n && cy + 1 < n && arr[cx + 1][cy + 1] != 1 && arr[cx+1][cy] == 0 && arr[cx][cy+1] == 0) q.push({ cx + 1,cy + 1,3 });
	}
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	cout<<BFS();
	return 0;
}