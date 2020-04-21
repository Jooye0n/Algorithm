#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
};
int n;
int arr[15][15];
point startP, endP;
 
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
 
int BFS() {
    int result = 0;
    bool chk[15][15] = { false, };
    queue<point> q;
    chk[startP.x][startP.y] = true;
    q.push(startP);
 
    while (q.empty() == false) {
        int size = q.size();
        while (size--) {
            int cx = q.front().x;
            int cy = q.front().y; q.pop();
            if (cx == endP.x && cy == endP.y) return result;
 
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && chk[nx][ny] == false && arr[nx][ny] != 1) {
                    if (arr[nx][ny] == 0) {
                        chk[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                    else if (arr[nx][ny] == 2) {
                        if ((result + 1) % 3 == 0) {
                            chk[nx][ny] = true;
                            q.push({ nx,ny });
                        }
                        else q.push({ cx,cy });
                    }
                     
                }
            }
        }
        result++;
    }
    return -1;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        cin >> startP.x >> startP.y;
        cin >> endP.x >> endP.y;
 
        printf("#%d %d\n", t, BFS());
    }
    return 0;
}