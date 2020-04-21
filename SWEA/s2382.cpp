#include <bits/stdc++.h>
using namespace std;
struct point {
    int num;
    int dir;
    int maxNum;//최대 군집 수
};
 
const int dx[5] = { 0,-1,1,0,0 };
const int dy[5] = { 0,0,0,-1,1 };
int n, m, k;
point arr[101][101];//구역
 
int getOtherSide(int d) {
    if (d == 1 || d == 3) return d + 1;
    else return d - 1;
}
 
int getResult() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += arr[i][j].num;
        }
    }
    return result;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(arr, 0, sizeof(arr));
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            cin >> arr[x][y].num >> arr[x][y].dir;
            arr[x][y].maxNum = arr[x][y].num;
        }
 
        while (m--) {
            point temp[101][101] = { false, };
 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i][j].dir == 0) continue;
 
                    int dir = arr[i][j].dir;
                    int num = arr[i][j].num;
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
 
                    if (nx == 0 || ny == 0 || nx == n - 1 || ny == n - 1) {//약품
                        if (num != 1) {
                            temp[nx][ny].num = (num / 2);
                            temp[nx][ny].dir = getOtherSide(dir);
                            temp[nx][ny].maxNum = (num / 2);
                        }
                    }
                    else {//약품 아님
                        if (temp[nx][ny].dir != 0) {//이미 군집 있음
                            int newnum = temp[nx][ny].maxNum;
                            if (num > newnum) {
                                temp[nx][ny].maxNum = num;
                                temp[nx][ny].dir = dir;
                            }
                            temp[nx][ny].num += num;
                        }
                        else {//비었음
                            temp[nx][ny].num = num;
                            temp[nx][ny].maxNum = num;
                            temp[nx][ny].dir = dir;
                        }
                    }
                }
            }
            memcpy(arr, temp, sizeof(temp));
        }
        printf("#%d %d\n", t, getResult());
    }
    return 0;
}