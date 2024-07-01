/*
https://www.acmicpc.net/problem/2931
*/

#include <cstdio>
#include <iostream>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m;
char arr[25][25];
char pipe[7] = {'|','-','+','1','2','3','4'};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

point Mp;

int outPipe(char pnum, int dir){
    //파이프 번호와 들어온 방향 주면 return 나올 방향
    //불가능한 경우 return -1

    switch(pnum){
        case '|':
        if(dir!=2 && dir!=0) return -1;
        else return dir;

        case '+':
        return dir;

        case '-':
        if(dir!=3 && dir!=1) return -1;
        else return dir;
        
        case '1':
        if(dir==0) return 1;
        else if(dir==3) return 2;
        else return -1;

        case '2':
        if(dir==2) return 1;
        else if(dir==3) return 0;
        else return -1;

        case '3':
        if(dir==1) return 0;
        else if(dir==2) return 3;
        else return -1;

        case '4':
        if(dir==1) return 2;
        else if(dir==0) return 3;
        else return -1;
    }
}

bool isright(int x, int y, int dir){
    int nx = x+dx[dir];
    int ny = y+dy[dir];

    if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]!='.'&& arr[nx][ny]!='M' && arr[nx][ny]!='Z' && outPipe(arr[nx][ny],dir)!= -1)
        return true;
    else 
        return false;
}

void goToBlank(int cx, int cy, int dir, int cnt){
    //현재 위치와 들어온 방향
    
    int outDir = outPipe(arr[cx][cy],dir);
    int nx = cx+dx[outDir];
    int ny = cy+dy[outDir];

    if(nx>=0 && ny>=0 && nx<n && ny<m){
        if(arr[nx][ny]=='.'){
            Mp.x = nx;
            Mp.y = ny;

            for(register int i=0; i<7; i++){
                int temp = outPipe(pipe[i],outDir);
                if(temp !=-1 && isright(nx,ny,temp)==true){
                    arr[nx][ny] = pipe[i];
                    if(i==2) goToBlank(nx,ny,outDir,cnt);
                    else goToBlank(nx,ny,outDir,cnt-1);
                    arr[nx][ny] = '.';
                }
            }

        }else if(arr[nx][ny]=='Z'){
            if(cnt==0){
                cout<<Mp.x+1<<' '<<Mp.y+1<<' '<<arr[Mp.x][Mp.y];
                exit(0);
            }
        }else{//파이프
            if(outPipe(arr[nx][ny],outDir)!=-1){
                goToBlank(nx,ny,outDir,cnt-1);
            }
        }
    }
}



int main(){
    cin>>n>>m;
    int cx,cy;
    int cnt=0;//지나가야하는 파이프 개수

    for(register int i=0; i<n; i++){
        string s;
        cin>>s;
        for(register int j=0; j<s.size(); j++){
            arr[i][j] = s[j];
            
            if(arr[i][j]!='M' && arr[i][j]!='Z' && arr[i][j]!='.') cnt++;
            if(arr[i][j]=='+') cnt++;
            if(arr[i][j]=='M'){
                cx = i;
                cy = j;
            }
        }
    }
    
    for(register int i=0; i<4; i++){
        int nx = cx+dx[i];
        int ny = cy+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]!='.' && arr[nx][ny]!='M' && arr[nx][ny]!='Z'){
            goToBlank(nx,ny,i,cnt);
        }
    }

    return 0;
}