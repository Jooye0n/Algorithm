#include <bits/stdc++.h>
using namespace std;
int n;
int arr[81];

bool chk(int x, int k) {
	//넣을 수 있으면 return true
	int fin = (x + 1) / 2;
	for (int i = 1; i <= fin; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[x - j] != arr[x - i - j]) break;
			if (j == i - 1) return false;
		}
	}
	return true;
}

void found(int x, int k) {
	if (x == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		exit(0);
	}
	else {
		for (int i = 1; i <= 3; i++) {
			arr[x] = i;
			if (chk(x, i) == true) {
				found(x + 1, i);
			}
		}
	}
}

int main() {
	cin >> n;
	found(0,0);
	return 0;
}