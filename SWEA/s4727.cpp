#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
    bool flag;//m주기 오작교 추가 여부
};
int n, m;
int arr[10][10];
 
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
 
int BFS() {
    int result = 0;
    bool chk[10][10][2] = { false, };
    queue<point> q;
    q.push({ 0,0,false });
    chk[0][0][0] = true;
 
    while (q.empty() == false) {
        int size = q.size();
        while (size--) {
            int cx = q.front().x;
            int cy = q.front().y; 
            bool cflag = q.front().flag; q.pop();
 
            if (cx == n - 1 && cy == n - 1) return result;
 
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
 
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && chk[nx][ny][cflag] == false) {
                    if (arr[nx][ny] == 0) {//절벽
                         
                        if (arr[cx][cy] > 1) continue;
                        if (cflag == true) continue;
                        if ((result + 1) % m == 0) {
                            chk[nx][ny][1] = true;
                            q.push({ nx,ny,true });
                        }
                        else q.push({ cx,cy,false });
                    }
                    else if (arr[nx][ny] == 1) {//길
                        chk[nx][ny][cflag] = true;
                        q.push({ nx,ny,cflag });
                    }
                    else if (arr[nx][ny] > 1) {//기존 오작교
                        if (arr[cx][cy] != 1) continue;
                        if ((result + 1) % arr[nx][ny] == 0) {
                            chk[nx][ny][cflag] = true;
                            q.push({ nx,ny,cflag });
                        }
                        else q.push({ cx,cy,cflag });
                    }
                }
            }
        }
        result++;
    }
 
    return 0;
}
int main() {
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
 
        printf("#%d %d\n", t, BFS());
    }
    return 0;
}