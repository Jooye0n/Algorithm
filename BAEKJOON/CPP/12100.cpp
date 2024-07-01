/*2048게임
6
2 2 0 0 0 4
2 2 2 4 4 4
2 0 0 2 0 0
2 0 0 0 2 0
2 4 2 4 4 2
2 2 0 0 8 8
*/
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct point {
	int x;
	int y;
};

int n;
int arr[21][21];
int maxNum;

void leftM() {
	queue<int> q;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j] != 0) {
				q.push(arr[i][j]);
				arr[i][j] = 0;
			}
		}

		int idx = 0;
		while (q.empty() == false)
		{
			int data = q.front(); q.pop();
			if (arr[i][idx] == 0) arr[i][idx] = data;
			else if (arr[i][idx] == data) arr[i][idx++] *= 2;
			else arr[i][++idx] = data;
		}
	}
}

void downM() {
	queue<int> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i] != 0) {
				q.push(arr[j][i]);
				arr[j][i] = 0;
			}
		}

		int idx = 0;

		while (q.empty() == false)
		{
			int data = q.front(); q.pop();

			if (arr[idx][i] == 0) arr[idx][i] = data;
			else if (arr[idx][i] == data) arr[idx++][i] *= 2;
			else arr[++idx][i] = data;
			
		}
	}
}

void rightM() {
	queue<int> q;

	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >=0; j--) {
			if (arr[i][j] != 0) {
				q.push(arr[i][j]);
				arr[i][j] = 0;
			}
		}

		int idx = n-1;

		while (q.empty() == false)
		{
			int data = q.front(); q.pop();

			if (arr[i][idx] == 0) arr[i][idx] = data;
			else if (arr[i][idx] == data) arr[i][idx--] *= 2;
			else arr[i][--idx] = data;
			
		}
	}
}


void upM() {
	queue<int> q;

	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >= 0; j--) {
			if (arr[j][i] != 0) {
				q.push(arr[j][i]);
				arr[j][i] = 0;
			}
		}

		int idx = n-1;

		while (q.empty() == false)
		{
			int data = q.front(); q.pop();

			if (arr[idx][i] == 0) arr[idx][i] = data;
			else if (arr[idx][i] == data) arr[idx--][i] *= 2;
			else arr[--idx][i] = data;
			
		}
	}
}

void goTo(int x) {
	switch (x) {
	case 0: leftM(); return;
	case 1: rightM(); return;
	case 2: downM(); return;
	case 3: upM(); return;
	}
}

void DFS(int x) {
	if (x == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maxNum < arr[i][j]) maxNum = arr[i][j];
			}
		}
		return;
	}
	
	int temp[21][21] = { 0, };
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = arr[i][j];
		}
    }

	for (int d = 0; d < 4; d++) {

		goTo(d);
		DFS(x + 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = temp[i][j];
			}
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

	DFS(0);
	cout << maxNum;
	return 0;
}