#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
};
int n, m, sx, sy, L;
int arr[50][50];
bool chk[50][50];
queue<point> q;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
int result;
 
bool isItRoute(int x, int y, int dir) {
    int np = arr[x][y];
    if (np == 0) return false;
    if (dir == 0) {
        if (np == 3 || np == 4 || np == 7) return false;
        else return true;
    }
    else if (dir == 1) {
        if (np == 2 || np == 4 || np == 5) return false;
        else return true;
    }
    else if (dir == 2) {
        if (np == 3 || np == 6 || np == 5) return false;
        else return true;
    }
    else if (dir == 3) {
        if (np == 2 || np == 6 || np == 7) return false;
        else return true;
    }
}
 
void pushQueue(int nx, int ny, int dir) {
    if (nx >= 0 && ny >= 0 && nx < n && ny < m && isItRoute(nx,ny,dir) == true && chk[nx][ny] == false) {
        chk[nx][ny] = true;
        q.push({ nx,ny });
        result++;
    }
}
 
 
void BFS() {
    result = 1;
    chk[sx][sy] = true;
    q.push({ sx,sy });
    while (L--) {
        int size = q.size();
        while (size--) {
            int cx = q.front().x;
            int cy = q.front().y; q.pop();
            int cnum = arr[cx][cy];
            switch (cnum)
            {
            case 1:
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    pushQueue(nx, ny, i);
                }
                break;
            case 2:
                for (int i = 0; i <= 2; i += 2) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    pushQueue(nx, ny, i);
                }
                break;
            case 3:
                for (int i = 1; i <= 3; i += 2) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    pushQueue(nx, ny, i);
                }
                break;
            case 4:
                for (int i = 0; i <= 1; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    pushQueue(nx, ny, i);
                }
                break;
            case 5:
                for (int i = 1; i <= 2; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    pushQueue(nx, ny, i);
                }
                break;
            case 6:
                for (int i = 2; i <= 3; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    pushQueue(nx, ny, i);
                }
                break;
            case 7:
                for (int i = 0; i <= 3; i+=3) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    pushQueue(nx, ny, i);
                }
                break;
            }
        }
    }
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(chk,false,sizeof(chk));
        while (q.empty() == false) q.pop();
        cin >> n >> m >> sx >> sy >> L;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        L--;
        BFS();
        printf("#%d %d\n", t, result);
    }
    return 0;
}