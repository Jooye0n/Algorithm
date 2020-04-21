#include <bits/stdc++.h>
#define MAX 1000
 
using namespace std;
int n, m;
char arr[20][20];
bool chk[20][20][4];
 
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
 
int getNextX(int cx, int dir) {
    cx = cx + dx[dir];
    if (cx < 0) cx = n - 1;
    else if (cx >= n) cx = 0;
    return cx;
}
 
int getNestY(int cy, int dir) {
    cy = cy + dy[dir];
    if (cy < 0) cy = m - 1;
    else if (cy >= m) cy = 0;
    return cy;
}
 
bool testProgram(int dir, int cx, int cy, int mem) {
    int cnt = MAX;
    while (cnt--) {
        char cur = arr[cx][cy];
        switch (cur)
        {
        case '<':
            dir = 3;
            break;
        case '>':
            dir = 1;
            break;
        case '^':
            dir = 2;
            break;
        case 'v':
            dir = 0;
            break;
        case '_': //메모리에 0이 저장되어 있으면 이동 방향을 오른쪽으로 바꾸고, 아니면 왼쪽으로 바꾼다.
            if (mem == 0) dir = 1;
            else dir = 3;
            break;
        case '|'://메모리에 0이 저장되어 있으면 이동 방향을 아래쪽으로 바꾸고, 아니면 위쪽으로 바꾼다.
            if (mem == 0) dir = 0;
            else dir = 2;
            break;
        case '?'://이동 방향을 상하좌우 중 하나로 무작위로 바꾼다. 방향이 바뀔 확률은 네 방향 동일하다.
            if (chk[cx][cy][0] == true && chk[cx][cy][1] == true && chk[cx][cy][2] == true && chk[cx][cy][3] == true) return false;
             
            for (int i = 0; i < 4; i++) {
                if (chk[cx][cy][i] == true) continue;
                chk[cx][cy][i] = true;
                if (testProgram(i, getNextX(cx,i), getNestY(cy,i), mem) == true) return true;
            }
            return false;
        case '.':
            break;
        case '@':
            return true;
        case '+': //메모리에 저장된 값에 1을 더한다. 만약 더하기 전 값이 15이라면 0으로 바꾼다.
            if (mem == 15) mem = 0;
            else mem++;
            break;
        case '-': //메모리에 저장된 값에 1을 뺀다.만약 빼기 전 값이 0이라면 15로 바꾼다.
            if (mem == 0) mem = 15;
            else mem--;
            break;
        default: // 0-9 (메모리에 문자가 나타내는 값을 저장한다.)
            mem = cur - '0';
            break;
        }
 
        cx = getNextX(cx, dir);
        cy = getNestY(cy, dir);
    }
 
    return false;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> m;
        memset(chk, false, sizeof(chk));
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                arr[i][j] = s[j];
            }
        }
        cout << '#' << t << ' ' << (testProgram(1,0,0,0) == true ? "YES" : "NO" ) << '\n';
    }
    return 0;
}