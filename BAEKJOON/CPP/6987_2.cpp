#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MAX 987987987
using namespace std;
struct point {
	int x, y, z;
};
vector<pair<int, int> > v; //승부 쌍 저장
point arr[6];
point ans[6];
pair<int, int> temp;

bool flag;

void choice(int x, int k) {
	if (x == 2) {
		v.push_back(temp);
	}
	else {
		for (int i = k; i < 6; i++) {
			if (x == 0) temp.first = i;
			else if (x == 1) temp.second = i;
			choice(x + 1, i + 1);
		}
	}
}

void fight(int x) {
	if (x == v.size()) {
		for (int i = 0; i < 6; i++) {
			if (arr[i].x != ans[i].x || arr[i].y != ans[i].y || arr[i].z != ans[i].z) return;
		}
		flag = true;
	}
	else {
		int t1 = v[x].first;
		int t2 = v[x].second;

		arr[t1].x++; arr[t2].z++;
		fight(x + 1);
		arr[t1].x--; arr[t2].z--;

		arr[t1].y++; arr[t2].y++;
		fight(x + 1);
		arr[t1].y--; arr[t2].y--;

		arr[t1].z++; arr[t2].x++;
		fight(x + 1);
		arr[t1].z--; arr[t2].x--;
	}
}

int main() {
	int T = 4;
	choice(0, 0);
	while (T--) {
		flag = false;
		for (int i = 0; i < 6; i++) {
			cin >> ans[i].x >> ans[i].y >> ans[i].z;
		}
		fight(0);
		cout << flag << ' ';
	}
	return 0;
}