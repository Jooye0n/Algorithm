#include <bits/stdc++.h>
using namespace std;
int n, L,result;
int arr[100][100];

void testCal(int x) {
	//y=x 세로줄 길 놓을 수 있으면 result++;
	int height = arr[0][x];
	int cnt = 1;
	for (int cx = 1; cx < n; cx++) {
		if (height == arr[cx][x]) cnt++;
		else if (height == arr[cx][x] - 1) {//높아짐
			if (cnt >= L) {
				cnt = 1;
				height = arr[cx][x];
			}
			else return;
		}
		else if(height == arr[cx][x] + 1){//낮아짐
			for (int i = cx; i < cx + L; i++) {
				if (i >= n) return;
				if (arr[cx][x] != arr[i][x]) return;
			}
			cnt = 0;
			cx += L-1;
			height = arr[cx][x];
		}
		else return;
	}
	result++;
}

void testRow(int x) {
	int height = arr[x][0];
	int cnt = 1;
	for (int cx = 1; cx < n; cx++) {
		if (height == arr[x][cx]) cnt++;
		else if (height == arr[x][cx] - 1) {//높아짐
			if (cnt >= L) {
				cnt = 1;
				height = arr[x][cx];
			}
			else return;
		}
		else if(height == arr[x][cx] + 1) {//낮아짐
			for (int i = cx; i < cx + L; i++) {
				if (i >= n) return;
				if (arr[x][cx] != arr[x][i]) return;
			}
			cnt = 0;
			cx += L-1;
			height = arr[x][cx];
		}
		else return;
	}
	result++;
}
int main() {
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		testCal(i);
		testRow(i);
	}

	cout << result;
	return 0;
}