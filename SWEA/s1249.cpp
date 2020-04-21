#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
    int x, y;
};
int n;
int arr[100][100];//손상 정도가 저장된 맵
int chk[100][100];//해당 칸 까지의 최소 시간이 저장된 맵
 
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
 
void BFS() {
    queue<point> q;
    chk[0][0] = 0;
    q.push({ 0,0 });
    while (q.empty() == false) {
        int cx = q.front().x;
        int cy = q.front().y; q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (chk[nx][ny] > chk[cx][cy] + arr[nx][ny]) {
                chk[nx][ny] = chk[cx][cy] + arr[nx][ny];
                q.push({ nx,ny });
            }
        }
    }
}
 
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            chk[i][j] = MAX;
        }
    }
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        init();
 
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                arr[i][j] = s[j]-'0';
            }
        }
 
        BFS();
        printf("#%d %d\n", t, chk[n - 1][n - 1]);
    }
    return 0;
}