#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
    int bound;
    int perfor;
};
 
const int dx[5] = { 0,0,1,0,-1 };
const int dy[5] = { 0,-1,0,1,0 };
 
int k, BC;
int A[101];
int B[101];
vector<point> v;//BC 모음
 
int ax, ay;
int bx, by;
 
int getDistance(int x, int y, int idx) {
    int x1 = v[idx].x;
    int y1 = v[idx].y;
 
    return abs(x1 - x) + abs(y1 - y);
}
 
int move(int x) {
    //x 초에서의 최대 충전 값 return
    int result = 0;
    ax = ax + dx[A[x]];
    ay = ay + dy[A[x]];
 
    bx = bx + dx[B[x]];
    by = by + dy[B[x]];
 
    vector<int> BC_a;
    vector<int> BC_b;
 
    for (int i = 0; i < v.size(); i++) {
        if (getDistance(ax, ay, i) <= v[i].bound) BC_a.push_back(i);
        if (getDistance(bx, by, i) <= v[i].bound) BC_b.push_back(i);
    }
 
    if (BC_a.size() == 0 && BC_b.size() == 0) return 0;
 
    if (BC_a.size() == 0 && BC_b.size() > 0) {
        for (int i = 0; i < BC_b.size(); i++) {
            result = max(result, v[BC_b[i]].perfor);
        }
        return result;
    }
 
    if (BC_b.size() == 0 && BC_a.size() > 0) {
        for (int i = 0; i < BC_a.size(); i++) {
            result = max(result, v[BC_a[i]].perfor);
        }
        return result;
    }
 
    for (int i = 0; i < BC_a.size(); i++) {
        for (int j = 0; j < BC_b.size(); j++) {
            int a = BC_a[i];
            int b = BC_b[j];
            int temp = 0;
 
            if (a == b) {
                temp += v[a].perfor;
            }
            else {
                temp += v[a].perfor;
                temp += v[b].perfor;
            }
 
            result = max(result, temp);
        }
    }
 
    return result;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int result = 0;
        v.clear();
        ax = 1; ay = 1;
        bx = 10; by = 10;
 
        cin >> k >> BC;
        for (int i = 1; i <= k; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= k; i++) {
            cin >> B[i];
        }
 
        for (int i = 0; i < BC; i++) {
            point p;
            cin >> p.x >> p.y >> p.bound >> p.perfor;
            v.push_back(p);
        }
 
        for (int i = 0; i <= k; i++) {//i 초
            result += move(i);
        }
 
        printf("#%d %d\n", t, result);
    }
    return 0;
}