
/*
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
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

int countTraser;
int T;
char arr[104][104];
bool chk[104][104][27];//alph
bool traser[104][104];
int result;
int n,m;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool lookChk(int cx, int cy, int nx, int ny){
    for(int i=0; i<27; i++){
        if(chk[cx][cy][i] != chk[nx][ny][i]) return false;
    }
    return true;
}


int BFS(int x, int y){
    int tempResult = 0;
    queue<point> q;
    point p = {x,y};
    q.push(p);

    while(q.empty()==false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();
        
        for(int i=0 ;i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(countTraser==tempResult) return countTraser;

            if(nx>=1 && ny>=1 && nx<=n+2 && ny<=m+2 && arr[nx][ny] !='*' && lookChk(cx,cy,nx,ny)==false){//똑같은 열쇠 들고 온적없으면 간다
                if(arr[nx][ny]=='.'){
                    for(int i=0 ; i<27; i++){
                        if(chk[cx][cy][i]==true)
                            chk[nx][ny][i] = chk[cx][cy][i];
                    }
                    point np = {nx,ny};
                    q.push(np);
                }

                else if(arr[nx][ny]>='a' && arr[nx][ny]<='z'){
                    for(int i=0 ;i<27; i++){
                        if(chk[cx][cy][i]==true)
                            chk[nx][ny][i] = chk[cx][cy][i];
                    }
                    chk[nx][ny][arr[nx][ny]-'a'] = true;
                    point np = {nx,ny};
                    q.push(np);
                }

                else if(arr[nx][ny]>='A' && arr[nx][ny]<='Z' && chk[cx][cy][arr[nx][ny]-'A']==true){
                    //열쇠가 있으면 가서 문열고
                    for(int i=0 ;i<27; i++){
                        if(chk[cx][cy][i]==true)
                            chk[nx][ny][i] = chk[cx][cy][i];
                    }
                    point np = {nx,ny};
                    q.push(np);
                }

                else if(arr[nx][ny]=='$'){

                    if(traser[nx][ny]==false){
                        traser[nx][ny]=true;
                        tempResult++;
                    }

                    for(int i=0 ;i<27; i++){
                        if(chk[cx][cy][i]==true)
                            chk[nx][ny][i] = chk[cx][cy][i];
                    }

                    point np = {nx,ny};
                    q.push(np);
                }
            } 
        }
    }

    return tempResult;
}

void initKey(int x, int y, string s){
    if(s[0]=='0'){
        chk[x][y][26] = true;
    }
    else{
        for(int i=0; i<s.size(); i++){
            int idx = s[i]-'a';
            chk[x][y][idx] = true;
        }
    }
}

int main(){
    cin>>T;
    for(int t=0; t<T; t++){
        cin>>n>>m;

        //init
        memset(chk,false,sizeof(chk));
        memset(traser,false,sizeof(traser));
        result = 0;
        countTraser = 0;

        for(int i=0; i<n+4; i++){
            for(int j=0; j<m+4; j++){
                if(i==0 || i==n+3 || j==0 || j==m+3) arr[i][j] = '*';
                else arr[i][j] = '.';
            }
        }

        for(int i=2; i<=n+1; i++){
            string s; cin>>s;
            for(int j=2; j<=m+1; j++){
                arr[i][j] = s[j-2];
                if(arr[i][j]=='$') countTraser++;
            }
        }

        string alreadyKey;
        cin>>alreadyKey;
        
        initKey(1,1,alreadyKey);
        int temp = BFS(1,1);
        if(temp>result) result=temp;
        cout<<result<<'\n';
    }
    return 0;
}
