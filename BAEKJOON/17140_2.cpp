#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int r, c, k;
int result = MAX;
int arr[100][100];

int operR(int n) {//n은 최대 사이즈
	int temp[100][100] = { 0, };
	int newN = 0;

	for (int i = 0; i < n; i++) {
		int chk[101] = { 0, };
		vector<pair<int, int> > v;
		int cnt = 0;

		for (int j = 0; j < 100; j++) {
			if (arr[i][j] != 0) chk[arr[i][j]]++;
		}

		for (int j = 1; j <= 100; j++) {
			if (chk[j] > 0) v.push_back(make_pair(chk[j], j));
		}

		sort(v.begin(), v.end());

		for (int j = 0; j < v.size(); j++, cnt += 2) {
			if (j * 2 + 1 >= 100) break;
			temp[i][j * 2] = v[j].second;
			temp[i][j * 2 + 1] = v[j].first;
		}

		newN = max(newN, cnt);
	}

	memcpy(arr, temp, sizeof(arr));
	return newN;
}

int operC(int m) {
	int temp[100][100] = { 0, };
	int newM = 0;

	for (int i = 0; i < m; i++) {
		int chk[101] = { 0, };
		vector<pair<int, int> > v;
		int cnt = 0;

		for (int j = 0; j < 100; j++) {
			if (arr[j][i] != 0) chk[arr[j][i]]++;
		}

		for (int j = 1; j <= 100; j++) {
			if (chk[j] > 0) v.push_back(make_pair(chk[j], j));
		}

		sort(v.begin(), v.end());

		for (int j = 0; j < v.size(); j++, cnt += 2) {
			if (j * 2 + 1 >= 100) break;
			temp[j * 2][i] = v[j].second;
			temp[j * 2 + 1][i] = v[j].first;
		}
		
		newM = max(newM, cnt);
	}

	memcpy(arr, temp, sizeof(arr));
	
	return newM;
}

void DFS(int x, int n, int m) {
	if (x >= result) return;
	if (arr[r][c] == k) {
		result = x;
		return;
	}
	
	if (n >= m) m = operR(n);
	else n = operC(m);
	
	DFS(x + 1, n, m);
}

int main() {
	cin >> r >> c >> k; r--; c--;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0,3,3);
	result == MAX ? cout << -1 : cout << result;
	return 0;
}