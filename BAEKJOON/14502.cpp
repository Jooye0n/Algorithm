/*
https://www.acmicpc.net/problem/14502
*/


#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>


using namespace std;

struct point{
    int x; int y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[8][8];
bool chk[8][8];
int n,m;
int safeZero = -3;//초기 안전영역 (벽 3개 세울거니까)
int result = 0;

vector<point> virus;
vector<point> safe;

int BFS(){
    //바이러스 퍼트리면서 안전영역 구하기
    //퍼진 개수 return

    int countVirus = 0;
    queue<point> q;

    for(int i=0; i<virus.size(); i++){
        int x = virus[i].x;
        int y = virus[i].y;

        chk[x][y] = true;
        point p = {x,y};
        q.push(p);

    }

    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] ==0 && chk[nx][ny] == false){
                countVirus++;
                chk[nx][ny] = true;
                point np = {nx,ny};
                q.push(np);
            }
        }
    }

    return countVirus;
}

void choice(int x, int k){
    //벽 3개 세우기
    if(x == 3){
        
        memset(chk,false,sizeof(chk));
        int safeTemp = safeZero;

        safeTemp-=BFS();
        

        if(result<safeTemp){
            result = safeTemp;
        }
        

    }else{
        for(int i=k; i<safe.size(); i++){
            arr[safe[i].x][safe[i].y] = 1;
            choice(x+1,i+1);
            arr[safe[i].x][safe[i].y] = 0;
        }
    }
}


int main(){
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0 ; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 0){
                point temp = {i,j};
                safe.push_back(temp);
                safeZero++;

            }else if(arr[i][j] == 2){
                point temp = {i,j};
                virus.push_back(temp);
            }
        }
    }

    choice(0,0);

    cout<<result;

    return 0;
}
