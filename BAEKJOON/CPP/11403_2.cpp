#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100][100];
bool chk[100];

void foundRoute(int x, int y) {
	for (int i = 0; i < n; i++) {
		if (arr[y][i] == true && chk[i] == false) {
			arr[x][i] = true;
			chk[i] = true;
			foundRoute(x, i);
		}
	}
}
 
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(chk, false, sizeof(chk));
		foundRoute(i, i);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}cout << '\n';
	}
	return 0;
}