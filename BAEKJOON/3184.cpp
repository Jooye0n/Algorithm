/*
https://www.acmicpc.net/problem/3184

첫 줄에는 두 정수 R과 C가 주어지며(3 ≤ R, C ≤ 250), 각 수는 마당의 행과 열의 수를 의미한다.
다음 R개의 줄은 C개의 글자를 가진다. 이들은 마당의 구조(울타리, 양, 늑대의 위치)를 의미한다.
*/


#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[251][251];
bool chk[251][251];
int cnt_o, cnt_v;
int n,m;

void found(int x, int y){
    //  영역마다 늑대와 양 수 센 후 전역에 업데이트
    queue<point> q;
    point p = {x,y};
    q.push(p);
    chk[x][y] = true;

    int tmp_o = 0;
    int tmp_v = 0;

    if(arr[x][y] == 3) tmp_v++;
    else if(arr[x][y] == 2) tmp_o++;

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            point cp = q.front(); q.pop();
            int cx = cp.x;
            int cy = cp.y;

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny] == false && arr[nx][ny] !=1){
                    if(arr[nx][ny] == 3) tmp_v++;
                    else if(arr[nx][ny] == 2) tmp_o++;
                    
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);

                }
            }
        }
    }

    if(tmp_o>tmp_v){
        cnt_o+=tmp_o;
    }else{
        cnt_v+=tmp_v;
    }

}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char temp;
            cin>>temp;
            if(temp == '#'){
                arr[i][j] = 1;
            }else if(temp == '.'){
                arr[i][j] = 0;
            }else if(temp == 'o'){
                arr[i][j] = 2;
            }else if(temp == 'v'){
                arr[i][j] = 3;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] !=1 && chk[i][j] == false){//영역마다 found
                found(i,j);
            }
        }
    }

    cout<<cnt_o<<' '<<cnt_v;
    
    return 0;
}