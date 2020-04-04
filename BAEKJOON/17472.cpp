/*
https://www.acmicpc.net/problem/17472
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10000

using namespace std;
struct point{
    int x;
    int y;
};

int numOfIsland;
int n,m;
int arr[10][10];
bool chk[10][10];
int set[10] = {0,1,2,3,4,5,6,7,8,9};//크루스칼 부모 표시용
vector<int> choiceIsland;
vector<pair<int,pair<int, int> > > orderOfIsland;
vector<point> island[7];

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int getStrictDistance(int sx, int sy, int eNum){
    //시작 섬의 한 점과 도착 섬 사이의 직선최소거리 구한다.
    int sNum = arr[sx][sy];
    int result = MAX;

    for(int i=0; i<4; i++){
        int tempResult = 0;
        int cx = sx;
        int cy = sy;

        while(true){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m) break;

            if(arr[nx][ny] == eNum){//도착 섬
                if(tempResult > 1)
                    result = min(tempResult,result);
                break;
            }else if(arr[nx][ny] == 0){//바다
                tempResult++;
            }else if(arr[nx][ny] == sNum){//출발 섬
                tempResult = 0;
            }else{//다른 섬
                break;
            }

            cx = nx; cy = ny;
        }
    }
    return result;//다리를 놓을 수 없는 경우 MAX return
}

int getDistance(){
    //choiceIsland 두 섬 사이의 최소 거리 구한다.
    int startI = choiceIsland[0];
    int endI = choiceIsland[1];
    int result = MAX;

    for(int i=0; i<island[startI].size(); i++){
        result = min(result,getStrictDistance(island[startI][i].x, island[startI][i].y, endI));
    }
    return result;
}

void choice(int x, int k){
    //두 섬을 선택한다.
    if(x == 2){
        int dist = getDistance();
        //cout<<choiceIsland[0]<<' '<<choiceIsland[1]<<' '<<dist<<'\n';
        orderOfIsland.push_back(make_pair(dist,make_pair(choiceIsland[0],choiceIsland[1])));
    }else{
        for(int i=k; i<=numOfIsland; i++){
            choiceIsland.push_back(i);
            choice(x+1,i+1);
            choiceIsland.pop_back();
        }
    }
}

void foundIsland(int x, int y){
    //섬마다 번호 붙인다.
    queue<point> q;
    chk[x][y] = true;
    arr[x][y] = numOfIsland;
    point p = {x,y};
    q.push(p);
    island[numOfIsland].push_back(p);

    while(q.empty() == false){
        
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny] == false && arr[nx][ny] == 1){
                chk[nx][ny] = true;
                point np = {nx,ny};
                arr[nx][ny] = numOfIsland;
                q.push(np);
                island[numOfIsland].push_back(np);
            }
        }
    }
}

int getParent(int x){
    if(set[x] == x) return x;
    else{
        set[x] = getParent(set[x]);
        return set[x];
    }
}

void unionParent(int x, int y){
    x = getParent(x);
    y = getParent(y);

    if(x<y){
        for(int i=1; i<=numOfIsland; i++){
            if(set[i] == y) set[i] = x;
        }
    }else{
        for(int i=1; i<=numOfIsland; i++){
            if(set[i] == x) set[i] = y;
        }
    }
}

bool find(int x, int y){
    x = getParent(x);
    y = getParent(y);

    if(x == y) return true;
    else return false;
}

int makeConnect(){
    //전체를 연결하며 MST만족시 종료한다.
    int result = 0;

    for(int i=0; i<orderOfIsland.size(); i++){
        int dist = orderOfIsland[i].first;
        if(dist == MAX) continue;
        int firstIsl = orderOfIsland[i].second.first;
        int secondIsl = orderOfIsland[i].second.second;

        if(find(firstIsl, secondIsl) == false){
            result += dist;
            unionParent(firstIsl,secondIsl);
        }
    }

    for(int i=2; i<=numOfIsland; i++){
        if(set[i] != set[1]) return -1;
    }

    return result;
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }  

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1 && chk[i][j] == false){
                numOfIsland++;
                foundIsland(i,j);
            }
        }
    }

    choice(0,1);
    sort(orderOfIsland.begin(), orderOfIsland.end());
    cout<<makeConnect();

    return 0;
}