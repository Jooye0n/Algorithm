#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
	int x, y;
};
int n, m, result = MAX;
int arr[50][50];
bool chk[13];//유지할 치킨집의 idx
vector<point> house;
vector<point> chicken;

int dist(int x, int y, int x1, int y1) {
	return abs(x - x1) + abs(y - y1);
}

int getDistance(int x, int y) {
	//집마다 치킨거리 return
	int tempResult = MAX;
	for (int i = 0; i < chicken.size(); i++) {
		if (chk[i] == false) continue;
		tempResult = min(tempResult, dist(chicken[i].x, chicken[i].y, x, y));
	}
	return tempResult;
}

void choice(int x, int k) {
	if (x == m) {
		int tempResult = 0;
		for (int i = 0; i < house.size(); i++) {
			tempResult += getDistance(house[i].x, house[i].y);
		}
		result = min(result, tempResult);
	}
	else {
		for (int i = k; i < chicken.size(); i++) {
			chk[i] = true;
			choice(x + 1, i + 1);
			chk[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back({ i,j });
			else if (arr[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	choice(0, 0);
	cout << result;
	return 0;
}