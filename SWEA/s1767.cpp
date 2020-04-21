#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
    int x, y;
};
 
int n,result, cntResult;
int arr[15][15];
vector<point> v;//core vector
int dist[15][4];//from core to V distance
 
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
 
void init() {
    cntResult = 0;
    result = MAX;
    v.clear();
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            arr[i][j] = 2;
        }
    }
}
 
bool chkConnect(int x, int d) {
    //d방향으로 연결 가능한가 여부 return
    int cx = v[x].x;
    int cy = v[x].y;
    int dis = 0;
 
    while (true) {
        int nx = cx + dx[d];
        int ny = cy + dy[d];
 
        if (arr[nx][ny] == 2) {
            dist[x][d] = dis;
            return true;
        }
        else if (arr[nx][ny] == 0) {
            cx = nx;
            cy = ny;
            dis++;
        }
        else if (arr[nx][ny] == 1) {
            dist[x][d] = -1;
            return false;
        }
    }
}
 
 
void chkRoute(int x, int d, int val, int p) {
    //d방향 연결 route chk
    int cx = v[x].x;
    int cy = v[x].y;
 
    while (true) {
        int nx = cx + dx[d];
        int ny = cy + dy[d];
 
        if (arr[nx][ny] == 2) {
            return;
        }
        else if (arr[nx][ny] == p) {//0 -> 1 || 1 -> 0
            cx = nx;
            cy = ny;
            arr[cx][cy] = val;
        }
    }
}
 
void simulationRoute(int x, int distance, int cnt) {
    //겹치지 않고 가능하다면 result update
    if (x == v.size()) {
        if (cnt > cntResult) {
            cntResult = cnt;
            result = distance;
        }
        else if (cnt == cntResult) {
            result = min(result, distance);
        }   
    }
    else {
        for (int i = 0; i < 5; i++) {
            if (i == 4) {//연결 안함 or 못함
                simulationRoute(x + 1, distance, cnt);
            }
            else {//i방향으로 연결 가능 시 연결
                if (chkConnect(x,i) == true) {
                    chkRoute(x, i, 1, 0);
                    simulationRoute(x + 1, distance + dist[x][i], cnt+1);
                    chkRoute(x, i, 0, 1);
                }
            }
        }
    }
}
 
int main() {
 
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
            }
        }
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (arr[nx][ny] == 2) break;
                        if (d == 3) {
                            v.push_back({ i,j });
                        }
                    }
                }
            }
        }
        simulationRoute(0,0,0);
        printf("#%d %d\n", t, result);
    }
    return 0;
}