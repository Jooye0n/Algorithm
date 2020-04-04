/*
미세먼지 안녕
https://www.acmicpc.net/problem/17144

첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 가 주어진다.
둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)가 주어진다. 
공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 미세먼지의 양이다. 
-1은 2번 위아래로 붙어져 있고, 가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다.

미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
확산되는 양은 Ar,c/5이고 소수점은 버린다.
(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
공기청정기가 작동한다.
공기청정기에서는 바람이 나온다.
위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

7 8 1
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int h,w,t;
int arr[1001][1001];
vector<point> machine;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int lowerDir(int d){
    //아래쪽 공기청정기 방향 변경 함수
    int dir = (d+1) % 4;
    return dir;
}

int upperDir(int d){
    //위쪽 공기청정기 방향 변경 함수
    int dir = (d+3) % 4;
    return dir;
}

void printAll(){
    cout<<'\n';
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout<<arr[i][j]<<' ';
        }cout<<'\n';
    }cout<<'\n';
}

void upperWind(){
    //모두 0이 되는 지점 계산해서 시간 줄이자
    int cx = machine[0].x;
    int cy = machine[0].y;

    int d = 1;
    int cnt=0;

    while(cnt<4){
        int nx = cx+dx[d];
        int ny = cy+dy[d];
        //c에 n의 값을 적는다. 

        if(nx>=0 && ny>=0 && nx<=machine[0].x && ny<w){
            if(arr[cx][cy] != -1){
                arr[cx][cy] = arr[nx][ny];
            }

            if(arr[nx][ny] == -1){
                arr[cx][cy] = 0;
                
            }

            cx=nx; cy=ny;
        }else{
            d = upperDir(d);
            cnt++;
        }
    }
}

void lowerWind(){
    //모두 0이 되는 지점 계산해서 시간 줄이자
    int cx = machine[1].x;
    int cy = machine[1].y;

    int d = 3;
    int cnt=0;

    while(cnt<4){
        int nx = cx+dx[d];
        int ny = cy+dy[d];
        //c에 n의 값을 적는다. 

        if(nx>=machine[1].x && ny>=0 && nx<h && ny<w){
            if(arr[cx][cy] != -1){
                arr[cx][cy] = arr[nx][ny];
            }

            if(arr[nx][ny] == -1){
                arr[cx][cy] = 0;
                
            }

            cx=nx; cy=ny;
        }else{
            d = lowerDir(d);
            cnt++;
        }
    }
}

void BFS(){
    queue<point> q;
    int temp[1001][1001] = {0, };

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(arr[i][j]>0){
                point p = {i,j};
                q.push(p);
            }
        }
    }
    
    int size= q.size();

    while(size--){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        int all = arr[cx][cy];
        int all_five = arr[cx][cy]/5;
        int cnt = 0;

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            
            if(nx>=0 && ny>=0 && nx<h && ny<w && arr[nx][ny] != -1){
                cnt++;
                temp[nx][ny] += all_five;
                point p = {nx,ny};
                q.push(p);
            }
        }
        temp[cx][cy] += arr[cx][cy]-all_five*cnt;
    }
    

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            arr[i][j] = temp[i][j];
        }
    }

    arr[machine[0].x][machine[0].y] = -1;
    arr[machine[1].x][machine[1].y] = -1;

}

int main(){
    cin>>h>>w>>t;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>arr[i][j];
            if(arr[i][j] == -1){
                point p = {i,j};
                machine.push_back(p);
            }
        }
    }
    
    while(t--){
        //확산
        BFS();
        //위쪽순환
        upperWind();
        //아래쪽순환
        lowerWind();
    }

    int cnt = 0;
    //남아있는 미세먼지의 양 구하기
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(arr[i][j]>0) cnt+=arr[i][j];
        }
    }

    cout<<cnt;
    return 0;
}
