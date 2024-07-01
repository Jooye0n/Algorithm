#include <bits/stdc++.h>
#define LIM 104
using namespace std;
struct point {
	int x, y;
};
bool arr[105][105];
int n, num, result;
int block[8][4][2][4] = {
		{{{},{}},{{},{}},{{},{}},{{},{}}},//0
		{{{0,1,2,3},{0,0,0,0}},{{0,0,0,0},{0,1,2,3}},{{},{}},{{},{}}},//1
		{{{0,0,1,1},{0,1,0,1}},{{},{}},{{},{}},{{},{}}},//2
		{{{1,1,0,0},{0,1,1,2}},{{0,1,1,2},{0,0,1,1}},{{},{}},{{},{}}},//3
		{{{0,0,1,1},{0,1,1,2}},{{0,1,1,2},{1,1,0,0}},{{},{}},{{},{}}},//4
		{{{0,1,1,1},{1,0,1,2}},{{0,1,1,2},{0,0,1,0}},{{0,0,0,1},{0,1,2,1}},{{0,1,1,2},{1,0,1,1}}},//5
		{{{1,1,1,0},{0,1,2,2}},{{0,1,2,2},{0,0,0,1}},{{0,0,0,1},{0,1,2,0}},{{0,0,1,2},{0,1,1,1}}},//6
		{{{0,1,1,1},{0,0,1,2}},{{0,1,2,0},{0,0,0,1}},{{0,0,0,1},{0,1,2,2}},{{2,0,1,2},{0,1,1,1}}},//7
};

int dx[8] = { 0,2,1,2,2,4,4,4 };

void chkBlock(int i, int j, int x, int s) {
	bool flag = false;

	for (int d = 0; d < 4; d++) {
		int cx = i + block[x][s][0][d];
		int cy = j + block[x][s][1][d];
		if (arr[cx][cy]) return;
	}

	for (int d = 0; d < 4; d++) {
		int cx = i + block[x][s][0][d];
		int cy = j + block[x][s][1][d];
		arr[cx][cy] = true;
	}

	for (int d = 0; d < 4; d++) {
		int cx = i + block[x][s][0][d];
		int cy = j + block[x][s][1][d];
		int nx = cx + 1;
		if (arr[nx][cy] == false) flag = true;
	}

	for (int d = 0; d < 4; d++) {
		int cx = i + block[x][s][0][d];
		int cy = j + block[x][s][1][d];
		arr[cx][cy] = false;
	}

	if (flag == false) result++;
}

void getResult(int x) {

	for (int i = 0; i < LIM; i++) {
		for (int j = 0; j < n; j++) {

			for (int s = 0; s < dx[x]; s++) {
				chkBlock(i,j,x,s);
			}
		}
	}
}

int main() {
	cin >> n >> num;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = LIM - 1; j >= LIM - x; j--) {
			arr[j][i] = true;
		}
		arr[LIM][i] = true;
	}
	
	getResult(num);
	cout << result;
	
	return 0;
}