#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
};
 
int n,result;
char arr[300][300];
int M[300][300];
bool chk[300][300];
 
const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };
 
int chk8(int x, int y) {
    //x,y 중심으로 8칸 검사
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (arr[nx][ny] == '*') cnt++;
    }
    return cnt;
}
 
void BFS(int x, int y) {
    queue<point> q;
    q.push({ x,y });
    chk[x][y] = true;
 
    while (q.empty() == false) {
        int cx = q.front().x;
        int cy = q.front().y; q.pop();
        int cnt = M[cx][cy];
        arr[cx][cy] = cnt + '0';
 
        if (cnt == 0) {
            for (int i = 0; i < 8; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (arr[nx][ny] == '.' && chk[nx][ny] == false) {
                    chk[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
    }
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        result = 0;
        memset(chk, false, sizeof(chk));
        memset(M, 0, sizeof(M));
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                arr[i][j] = s[j];
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(arr[i][j] == '.') M[i][j] = chk8(i, j);
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (chk[i][j] == false && M[i][j] == 0 && arr[i][j] == '.') {
                    BFS(i, j);
                    result++;
                }
            }
        }
         
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '.') result++;
            }
        }
 
        printf("#%d %d\n", t, result);
    }
 
    return 0;
}