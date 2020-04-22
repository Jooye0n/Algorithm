#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

bool chk[MAX];
int arr[MAX];
int F, S, G, U, D;
int result = -1;

void BFS() {
	queue<int> q;
	chk[S] = true;
	q.push(S);
	int cnt = 0;

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int x = q.front(); q.pop();
			if (x == G) result = cnt;
			int nx = x + U;
			int ny = x - D;
			if (nx <= F && chk[nx] == false) {
				chk[nx] = true;
				q.push(nx);
			}
			if (ny >= 1 && chk[ny] == false) {
				chk[ny] = true;
				q.push(ny);
			}
		}
		cnt++;
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	BFS();
	result == -1 ? cout << "use the stairs" : cout << result;
	return 0;
}