#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
};
 
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
int n, m;
int arr[10][10];
vector<point> v; //바이러스 담음
point samsung;
int result;
 
void makeMap() {
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            arr[i][j] = 4;
        }
    }
}
 
int findRoute() {
    int cnt = 0;
    bool chk[10][10] = { false, };
    queue<point> q;
    queue<point> virus;
    q.push(samsung);
    chk[samsung.x][samsung.y] = true;
 
    for (int i = 0; i < v.size(); i++) {
        virus.push(v[i]);
    }
 
    while (q.empty() == false) {
 
        int vsize = virus.size();
        while (vsize--) {
            int cx = virus.front().x;
            int cy = virus.front().y; virus.pop();
 
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx<1 || ny<1 || nx>n || ny>m) continue;
                if (arr[nx][ny] == 0) {
                    arr[nx][ny] = 2;
                    virus.push({ nx,ny });
                }
            }
        }
 
        int size = q.size();
        while (size--) {
            int cx = q.front().x;
            int cy = q.front().y; q.pop();
 
            if (arr[cx][cy] == 4) return cnt;
 
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx<0 || ny<0 || nx>n+1 || ny>m+1) continue;
                if (arr[nx][ny] == 2 || arr[nx][ny] == 1 || chk[nx][ny] == true) continue;
                chk[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
 
        cnt++;
    }
    return -1;
}
 
void canEscape() {
    queue<point> q;
    bool chk[10][10] = { false, };
    q.push(samsung);
    chk[samsung.x][samsung.y] = true;
 
    while (q.empty() == false) {
        int cx = q.front().x;
        int cy = q.front().y; q.pop();
 
        if (arr[cx][cy] == 4) {
            int temp = findRoute();
            result = (temp == -1) ? -2 : temp;
            return;
        }
 
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx<0 || ny<0 || nx>n+1 || ny>m+1) continue;
            if (arr[nx][ny] == 1 || chk[nx][ny] == true) continue;
             
            chk[nx][ny] = true;
            q.push({ nx,ny });
 
        }
    }
    result = -1;
}
 
void printAll() {
    cout << '\n';
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            cout << arr[i][j] << ' ';
        }cout << '\n';
    }
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
 
        cin >> n >> m;
        result = 0;
        v.clear();
        makeMap();
         
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 2) {
                    v.push_back({ i,j });
                }
                else if (arr[i][j] == 3) {
                    arr[i][j] = 0;
                    samsung.x = i; samsung.y = j;
                }
            }
        }
        //printAll();
        canEscape();
 
        if (result == -1) {//CANNOT ESCAPE
            printf("#%d CANNOT ESCAPE\n", t);
        }
        else if (result == -2) {//ZOMBIE
            printf("#%d ZOMBIE\n", t);
        }
        else {
            printf("#%d %d\n", t, result);
        }
    }
    return 0;
}