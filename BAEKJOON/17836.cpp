/*
6 6 16
0 0 0 0 1 1
0 0 0 0 0 2
1 1 1 0 1 0
0 0 0 0 0 0
0 1 1 1 1 1
0 0 0 0 0 0
*/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
    bool flag;
};

int n,m,t;
int arr[101][101];
bool chk[101][101][2];

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int goToPrincess(){
    int result = 0;
    queue<point> q;
    chk[1][1][0] = true;
    point p = {1,1,false};
    q.push(p);

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; 
            bool cflag = q.front().flag; q.pop();

            if(cx == n && cy == m) return result;

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>0 && ny>0 && nx<=n && ny<=m){
                    if(cflag == false && arr[nx][ny] == 1) continue;
                    
                    point np = {nx,ny,cflag};
                    if(arr[nx][ny] == 2){
                        np.flag = true;
                    }

                    if(chk[nx][ny][np.flag] == true) continue;
                    chk[nx][ny][np.flag] = true;
                    q.push(np);
                }
            }
        }
        result++;
    }
    return -1;
}

int main(){
    cin>>n>>m>>t;
    for(int i=1 ;i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    int result = goToPrincess();
    (result == -1 || result >t) ? cout<<"Fail" : cout<<result;
    return 0;
}