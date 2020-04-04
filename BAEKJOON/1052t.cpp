/*
[ maze problem ]- c코드 모법답안 분석용
라비다 1052
미로찾기.
S에서 E까지 가는 최대한 빨리 도달할 때 몇 번 움직여야 하는가

입력
1 //몇번 수행할지
5 5 //n*m
S-###
-----
##---
E#---
---##

출력
9

*/

#include <stdio.h>
#include <queue>

using namespace std;
char map[110][110] = {0};//입력받을 공간
char chk[110][110] = {0};//방문했는지 확인

int sy, sx;//시작점
int ey, ex;//끝점

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int n, int m) {
    queue<int> qx;//x값
    queue<int> qy;//y값
    queue<int> cost;//단계
    qx.push(sx), qy.push(sy), cost.push(0);
    chk[sy][sx] = 1;//현재 점 방문했다고 체크
    
    int result = -1;
    while(!qx.empty()) {
        int cx = qx.front(); qx.pop();//이번에 보게 될 x
        int cy = qy.front(); qy.pop();//이번에 보게 될 y
        int cc = cost.front(); cost.pop();//현재 단계
        if(map[cy][cx] == '#')
        continue;
        if(cx == ex && cy == ey) {
            result = cc;
            break;
        }
        for(int i=0; i<4;i++) {
            if(cx+dx[i] >=0 && cy+dy[i] >=0 && cx+dx[i]<=n-1 &&cy+dy[i]<=n-1) { //구역 안에 있다면
                if(chk[cy+dy[i]][cx+dx[i]] == 0) {//방문 안했으면(넣으면서 체크하면 중복 막을 수 있다.)
                    qx.push(cx + dx[i]);
                    qy.push(cy + dy[i]);
                    cost.push(cc + 1);
                    chk[cy + dy[i]][cx + dx[i]] = 1;
                }
            }
        }
    }
    printf("%d\n", result);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++) {
            scanf("%s", map[i]);
        }
        for(int i=0; i<n;i++) {//시작점과 끝점이 어디있는지 찾아준다
            for(int j=0;j<m;j++) {
                if(map[i][j] == 'S') sy = i, sx = j;
                if(map[i][j] == 'E') ey = i, ex = j;
            }
        }
        bfs(n, m);//bfs
    }
    return 0;
    
}