#include <bits/stdc++.h>
using namespace std;
int n = 9;
int arr[9][9];
bool cal[9][10]; //th  num
bool row[9][10];

const int dx[9] = { 0,0,0,3,3,3,6,6,6 };
const int dy[9] = { 0,3,6,0,3,6,0,3,6 };

void printAll() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}cout << '\n';
	}
}

bool testSquare() {
	for (int i = 0; i < 9; i++) {
		bool chk[10] = { false, };
		for (int cx = dx[i]; cx < dx[i] + 3; cx++) {
			for (int cy = dy[i]; cy < dy[i] + 3; cy++) {
				if (arr[cx][cy] == 0) continue;
				if (chk[arr[cx][cy]] == true) return false;
				else chk[arr[cx][cy]] = true;
			}
		}
	}
	return true;
}

void DFS(int x) {
	if (x == 81) {
		printAll();
		exit(0);
	}
	else {
		int cx = x / n;
		int cy = x % n;
		if (arr[cx][cy] > 0) DFS(x + 1);
		else {
			for (int i = 1; i <= n; i++) {
				if (row[cx][i] == false && cal[cy][i] == false && testSquare() == true) {
					row[cx][i] = true;
					cal[cy][i] = true;
					arr[cx][cy] = i;
					DFS(x + 1);
					row[cx][i] = false;
					cal[cy][i] = false;
					arr[cx][cy] = 0;
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) row[i][arr[i][j]] = true;
			if (arr[j][i] > 0) cal[i][arr[j][i]] = true;
		}
	}

	DFS(0);
	return 0;
}