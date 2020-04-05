// 중량제한
#include <bits/stdc++.h>
#define MAX 10001
#define LIMIT 1000000001
using namespace std;

struct point {
	int dest;
	int w;
};

int n, m;
vector<point> v[MAX]; //중량 제한 적음
int startP, endP;
int mid;

bool CanFinish(int x) {
	//중량이 x인 짐의 이동 가능여부 return
	queue<int> q;
	bool chk[MAX] = { false, };
	chk[startP] = true;
	q.push(startP);

	while (q.empty() == false) {
		int cx = q.front(); q.pop();
		if (cx == endP) return true;
		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i].dest;
			if (v[cx][i].w >= mid && chk[nx] == false) {
				chk[nx] = true;
				q.push(nx);
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b, w; cin >> a >> b >> w;
		v[a].push_back({ b,w });
		v[b].push_back({ a,w });
	}
	cin >> startP >> endP;

	int start = 0;
	int end = LIMIT;

	while (start + 1 < end) {

		mid = (start + end) / 2;
		
		if (CanFinish(startP) == true) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	cout << start;
	return 0;
}