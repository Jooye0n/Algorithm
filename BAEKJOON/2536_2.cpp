#include <bits/stdc++.h>
using namespace std;
struct Bus {
	int sx, sy;
	int ex, ey;
};

struct point {
	int x, y;
};

int n, m;
vector<Bus> bus;
int sx, sy, ex, ey;
int chk[5001];

bool chkBusRoute(int x, int y, int num) {
	//num번 버스가 x,y를 지나면 return true;
	if (bus[num].ex == bus[num].sx && bus[num].sx == x && // -
		( min(bus[num].ey, bus[num].sy) <= y && max(bus[num].ey, bus[num].sy) >=y)) return true;
	else if(bus[num].ey == bus[num].sy && bus[num].sy == y && //|
		(min(bus[num].ex, bus[num].sx) <= x && max(bus[num].ex, bus[num].sx) >= x)) return true;

	return false;
}

bool crossBus(int num, int y) {
	//num 버스와 y버스의 노선이 겹치면 return true;
	if (bus[num].ex == bus[num].sx) { // -
		if (bus[y].ex == bus[y].sx && bus[y].ex == bus[num].ex) { // -
			if (min(bus[y].ey, bus[y].sy) <= max(bus[num].ey, bus[num].sy) &&
				min(bus[num].ey, bus[num].sy) <= max(bus[y].ey, bus[y].sy)) return true;
		}
		else if(bus[y].ey == bus[y].sy){ // |
			if (min(bus[y].ex, bus[y].sx) <= bus[num].ex && max(bus[y].ex, bus[y].sx) >= bus[num].ex &&
				min(bus[num].ey, bus[num].sy) <= bus[y].ey && max(bus[num].ey, bus[num].sy) >= bus[y].ey) return true;
		}
	}
	else {// |
		if (bus[y].ey == bus[y].sy && bus[num].sy == bus[y].sy) { // |
			if (min(bus[y].ex, bus[y].sx) <= max(bus[num].ex, bus[num].sx) &&
				min(bus[num].ex, bus[num].sx) <= max(bus[y].ex, bus[y].sx)) return true;
		}
		else if(bus[y].ex == bus[y].sx){ // -
			if (min(bus[y].ey, bus[y].sy) <= bus[num].ey && max(bus[y].ey, bus[y].sy) >= bus[num].ey &&
				min(bus[num].ex, bus[num].sx) <= bus[y].ex && max(bus[num].ex, bus[num].sx) >= bus[y].ex) return true;
		}
	}

	return false;
}

int BFS() {
	int result = 1;
	queue<int> q; //버스 번호 담는다.
	for (int i = 0; i < bus.size(); i++) {
		if (chkBusRoute(sx, sy, i)) {
			q.push(i);
			chk[i] = 1;
		}
	}

	for (int i = 0; i < bus.size(); i++) {
		if (chkBusRoute(ex, ey, i)) {
			chk[i] = 2;
		}
	}

	while (q.empty() == false) {
		int size = q.size();
		while (size--) {
			int cx = q.front(); q.pop();
			if (chk[cx] == 2) return result;

			for (int i = 0; i < bus.size(); i++) {
				if (chk[i] != 1 && crossBus(cx,i) == true) {
					if(chk[i] == 0) chk[i] = 1;
					q.push(i);
				}
			}
		}
		result++;
	}
}

int main() {
	cin >> m >> n;
	int T; cin >> T;
	while (T--) {
		int num, sx, sy, ex, ey;
		cin >> num >> sx >> sy >> ex >> ey;
		bus.push_back({ n - sy, sx - 1,n - ey, ex - 1 });
	}

	int x, x1, y, y1; cin >> x >> y >> x1 >> y1;
	sx = n - y; sy = x - 1; ex = n - y1; ey = x1 - 1;

	cout << BFS();
	return 0;
}