/*
https://www.acmicpc.net/problem/2933
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <memory.h>
#include <string>

using namespace std;

struct point{
    int x;
    int y;
};

char arr[100][100];
bool chk[100][100];
int n,m;
int cntX;

int stickNum;
int stick[100];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void printAll(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j];
        }cout<<'\n';
    }
}

int BFS(int x, int y){
    //x의 개수 세서 return 
    int temp = 1;

    queue<point> q;
    chk[x][y] = true;
    point p = {x,y};
    q.push(p);

    while(q.empty()==false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny]==false && arr[nx][ny]=='x'){
                point np = {nx,ny};
                chk[nx][ny] = true;
                q.push(np);
                temp++;
            }
        }
    }

    return temp;
}

void downX(){
    //chk 되지 않은 x 바닥으로 내리기
    //땅이나 chk된 x 만나면 끝
    //모양이 유지되어야 한다.

    queue<point> q;
    for(int i=0 ;i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='x' && chk[i][j]==false){
                arr[i][j]='.';
                point p = {i,j};
                q.push(p);
            }
        }
    }

    bool flag = false;

    while(true){
        //모든 점의 x를 ++하면서 chk true와 닿으면 그만
        //그 정도만큼 내린다.
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();
            if(cx==n || (arr[cx][cy]=='x' && chk[cx][cy]==true)) flag = true;

            cx++;
            point np = {cx,cy};
            q.push(np);
        }
        
        if(flag==true){
            int size = q.size();
            while(size--){
                int cx = q.front().x-2;
                int cy = q.front().y; q.pop();

                arr[cx][cy] = 'x';
            }
            break;
        }
    }


}

bool throwStick(int x, int d){
    //모든 높이는 1과 R사이이며, 높이 1은 행렬의 가장 바닥, R은 가장 위
    //미네랄 깼는지 여부
    //깨고나서 '.'로 바꿔줘야한다.
    int cx = n-x;

    if(d == -1){//<-
        for(int i=m-1; i>=0 ; i--){
            if(arr[cx][i]=='x'){
                arr[cx][i] = '.';
                return true;
            }
        }
    }else if(d==1){//->
        for(int i=0; i<m; i++){
            if(arr[cx][i]=='x'){
                arr[cx][i] = '.';
                return true;
            }
        }
    }
    return false;
}


int main(){
    int dir = 1;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0 ;j<m; j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='x') cntX++;
        }
    }
    
    cin>>stickNum;
    for(int i=0 ;i<stickNum; i++){
        cin>>stick[i];
        if(throwStick(stick[i],dir)==true){//미네랄 깼으면,

            cntX--;//미네랄 수 1 감소
            int temp = 0;
            memset(chk,false, sizeof(chk));

            for(int j=0; j<m; j++){
                if(arr[n-1][j]=='x' && chk[n-1][j]==false){
                    temp += BFS(n-1,j);
                }
            }
            
            if(temp != cntX) downX();//클러스터 1 아니면 미네랄 내리기
        } 
        //printAll();
        dir *= -1;
    }

    printAll();

    return 0;
}