/*
연구소3
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m;
int arr[51][51];
int chk[51][51];
int result= 987987987;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

vector<point> virus;
vector<int> liveVirus;

int countTime(){
    int maXNum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(chk[i][j] == -1 && arr[i][j] == 0) return -1;
            if(chk[i][j]>maXNum && arr[i][j] == 0) maXNum = chk[i][j];
        }
    }

    return maXNum;
}

void getCount(){
    queue<point> q;
    
    memset(chk,-1,sizeof(chk));

    for(int i=0; i<m; i++){
        q.push(virus[liveVirus[i]]);
        chk[virus[liveVirus[i]].x][virus[liveVirus[i]].y] = 0;//바이러스는 0으로
    }

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();
            for(int i=0 ;i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && arr[nx][ny] !=1){
                    if(chk[nx][ny] == -1 || chk[nx][ny]>chk[cx][cy]+1){
                        point p = {nx,ny};
                        chk[nx][ny] = chk[cx][cy]+1;
                        q.push(p);   
                    }
                }
            }
        }
    }
    //printChk();
    int total = countTime();
    if(total == -1 ) return;
    else if(result>total) result = total;
}
void found(int x, int k){
    //바이러스 m개 다골랐다.
    if(x == m){
        //고른 후 다 채운 후에 최소 초 업데이트
        getCount();

    }else{
        for(int i=k; i<virus.size(); i++){
            liveVirus.push_back(i);
            found(x+1,i+1);
            liveVirus.pop_back();
        }
    }
}

int main(){
    cin>>n>>m;


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 2){//바이러스 가능성
                point p = {i,j};
                virus.push_back(p);
            }
        }
    }

    //바이러스 고르기 -> 다 고른 후엔 전부 채워지는 시간 측정하기
    found(0,0);
    if(result != 987987987)
        cout<<result;
    else cout<<-1;

    return 0;
}