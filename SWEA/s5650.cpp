#include <bits/stdc++.h>
using namespace std;
int n;
int maxNum;
int arr[102][102];
 
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
 
int startX, startY;
 
int getDir(int dir, int num) {
    if (num == 1) {
        if (dir == 2) return 1;
        else if (dir == 3) return 0;
        else return (dir + 2) % 4;
    }
    else if (num == 2) {
        if (dir == 0) return 1;
        else if (dir == 3) return 2;
        else return (dir + 2) % 4;
    }
    else if (num == 3) {
        if (dir == 1) return 2;
        else if (dir == 0) return 3;
        else return (dir + 2) % 4;
    }
    else if (num == 4) {
        if (dir == 2) return 3;
        else if (dir == 1) return 0;
        else return (dir + 2) % 4;
    }
    else{
        return (dir + 2) % 4;
    }
}
 
pair<int, int> foundOther(int x, int y) {
    int num = arr[x][y];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == num && (i != x || j != y)) {
                return make_pair(i, j);
            }
        }
    }
}
 
int simulation(int x, int y, int d) {
    int result = 0;
    while (true) {
        int nx = x + dx[d];
        int ny = y + dy[d];
 
        if (nx <= 0 || ny <= 0 || nx > n || ny > n) {//벽
            result++;
            x = nx;
            y = ny;
            d = (d + 2) % 4;
        }
        else if (arr[nx][ny] >= 1 && arr[nx][ny] <= 5) {//블록
            result++;
            x = nx;
            y = ny;
            d = getDir(d, arr[nx][ny]);
        }
        else if (arr[nx][ny] == -1 || (nx == startX && ny == startY)) {//종료
            break;
        }
        else if (arr[nx][ny] >= 6 && arr[nx][ny] <= 10) {//웜홀
            pair<int, int> p = foundOther(nx, ny);
            x = p.first;
            y = p.second;
        }
        else {//보통 땅
            x = nx;
            y = ny;
        }
    }
    return result;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(arr, 0, sizeof(arr));
        vector<pair<int, int> >ground;
        maxNum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 0) ground.push_back(make_pair(i, j));
            }
        }
 
        for (int i = 0; i < ground.size(); i++) {
            for (int d = 0; d < 4; d++) {
                startX = ground[i].first;
                startY = ground[i].second;
                maxNum = max(maxNum, simulation(startX, startY, d));
            }
        }
 
        printf("#%d %d\n",t, maxNum);
    }
    return 0;
}