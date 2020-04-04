/*
드래곤커브
https://www.acmicpc.net/problem/15685

첫째 줄에 드래곤 커브의 개수 N(1 ≤ N ≤ 20)이 주어진다. 
둘째 줄부터 N개의 줄에는 드래곤 커브의 정보가 주어진다. 
드래곤 커브의 정보는 네 정수 x, y, d, g로 이루어져 있다. 
x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대이다. (0 ≤ x, y ≤ 100, 0 ≤ d ≤ 3, 0 ≤ g ≤ 10)
입력으로 주어지는 드래곤 커브는 격자 밖으로 벗어나지 않는다. 드래곤 커브는 서로 겹칠 수 있다.
방향은 0, 1, 2, 3 중 하나이고, 다음을 의미한다.

0: x좌표가 증가하는 방향 (→)
1: y좌표가 감소하는 방향 (↑)
2: x좌표가 감소하는 방향 (←)
3: y좌표가 증가하는 방향 (↓)
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};


bool arr[101][101];
int n;

int changeDir(int x, int y){
    int dir;

    if(x == -1) dir = 3;
    else if(x == 1) dir = 1;
    else if(y == -1) dir = 2;
    else if(y == 1) dir = 0;

    return dir;
}

void draw(int x, int y, int d, int g){
    //x,y부터 d방향 g세대 그려라
    vector<point> v;
    arr[x][y] = true;
    point p = {x,y};
    v.push_back(p);

    arr[x+dx[d]][y+dy[d]] = true;
    p.x = x+dx[d]; p.y = y+dy[d];
    v.push_back(p);
    
    //printAll();

    while(g--){
        for(int i=v.size()-1; i>0; i--){
            int cx = v[i].x;
            int cy = v[i].y;

            int sx = v[i].x - v[i-1].x;
            int sy = v[i].y - v[i-1].y;

            int dir = changeDir(sx,sy);

            int nx = v[v.size()-1].x+dx[dir];
            int ny = v[v.size()-1].y+dy[dir];
            //if(nx<0 || ny<0 || nx>100 || ny>100) return;
            arr[nx][ny] = true;
            p.x = nx; p.y = ny;
            v.push_back(p);
        }//printAll();
    }
}

int main(){
    int cnt = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        draw(x,y,d,g);
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            //왼쪽 위 첫점으로 사각형 검사
            if(arr[i][j] == true && arr[i+1][j] == true && arr[i][j+1] == true && arr[i+1][j+1] == true) cnt++;
        }
    }

    cout<<cnt;
    return 0;
}


