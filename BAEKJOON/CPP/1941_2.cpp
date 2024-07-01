#include <bits/stdc++.h>
using namespace std;
char arr[5][5];
bool group[5][5];
bool chk[5][5];
int result;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int chain(int x, int y) {
	int cnt = 1;
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || chk[nx][ny] == true || group[nx][ny] == false) continue;
		cnt += chain(nx, ny);
	}
	return cnt;
}

void choice(int x, int k, int cnt) {
	//25C7 중 S>=4인 조합 구하기
	if (x == 7) {
		memset(chk, false, sizeof(chk));
		if (cnt>=4 && chain((k-1)/5,(k-1)%5) == 7) result++;
	}
	else {
		for (int i = k; i < 25; i++) {
			int cx = i / 5;
			int cy = i % 5;
			group[cx][cy] = true;
			
			if (arr[cx][cy] == 'S') choice(x + 1, i + 1, cnt + 1);
			else choice(x + 1, i + 1, cnt);
			
			group[cx][cy] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < 5; j++) {
			arr[i][j] = s[j];
		}
	}

	choice(0, 0, 0);
	cout << result;
	return 0;
}