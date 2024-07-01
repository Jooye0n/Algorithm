/*
https://www.acmicpc.net/problem/3197
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m;

char arr[1500][1500];
bool chk[1500][1500];//백조 0의chk는 2 백조 1의 chk는 1
bool waterChk[1500][1500];
queue<point> water;
vector<point> endSwan;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {-1,1,0,0};

void printAll(){
    cout<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<chk[i][j]<<' ';
        }cout<<'\n';
    }
}

int oneDay(){
    int result = 0;
    queue<point> q;
    chk[endSwan[0].x][endSwan[0].y] = true;
    q.push(endSwan[0]);

    while(true){

        while(q.empty() == false){
            int size = q.size();
            while(size--){
                int cx = q.front().x;
                int cy = q.front().y; q.pop();

                if(cx == endSwan[1].x && cy == endSwan[1].y) return result;

                for(int i=0; i<4; i++){
                    int nx = cx+dx[i];
                    int ny = cy+dy[i];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && arr[cx][cy] == '.' && chk[nx][ny] == false){
                        if(arr[nx][ny] == '.'){
                            chk[nx][ny] = true;
                            point np = {nx,ny};
                            q.push(np);
                        }else if(arr[nx][ny] == 'X'){
                            chk[nx][ny] = true;
                        }
                    }
                }
            }
        }



        int waterSize = water.size();
        while(waterSize--){
            int cx = water.front().x;
            int cy = water.front().y; water.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] == 'X'){
                    arr[nx][ny] = '.';
                    point np = {nx,ny};
                    water.push(np);

                    if(chk[nx][ny] == true){
                        q.push(np);
                    }
                }
            }
        }

        result++;
    }
}


int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j];
            if(arr[i][j] == 'L'){
                point p = {i,j};
                endSwan.push_back(p);
                arr[i][j] = '.';
            }
            if(arr[i][j] == '.'){
                point p = {i,j};
                water.push(p);
            }
        }
    }

    cout<<oneDay();

    return 0;
}