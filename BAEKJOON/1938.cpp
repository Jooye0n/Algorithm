/*
https://www.acmicpc.net/problem/1938
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

struct tree{
    int x;
    int y;
    int dir;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n;
int result;
char arr[50][50];
bool chk[50][50][2];
vector<point> startP;
vector<point> endP;
tree endT;

bool turnBound(int x, int y){
    int tx[8] = {-1,-1,-1,0,0,1,1,1};
    int ty[8] = {-1,0,1,-1,1,-1,0,1};

    for(int i=0; i<8; i++){
        int nx = x+tx[i];
        int ny = y+ty[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n || arr[nx][ny]=='1') return false;
    }
    return true;
}

bool moveBound1(int x, int y){
    //나를 포함한 양쪽이 1.나무 있는지 2.범위 안에 있는지
    if(x>=n || y+1>=n || x<0 || y-1<0) return false;
    if(arr[x][y]=='0' && arr[x][y-1]=='0' && arr[x][y+1]=='0') return true;
    else return false;
}

bool moveBound2(int x, int y){
    //나를 포함한 양쪽이 1.나무 있는지 2.범위 안에 있는지
    if(x+1>=n || y>=n || x-1<0 || y<0) return false;
    if(arr[x-1][y]=='0' && arr[x][y]=='0' && arr[x+1][y]=='0') return true;
    else return false;
}

tree turnPointToTree(vector<point> v){
    tree t;
    if(v[0].x==v[1].x){
        t.x = v[1].x;
        t.y = v[1].y;
        t.dir = 0;
    }else if(v[0].y==v[1].y){
        t.x = v[1].x;
        t.y = v[1].y;
        t.dir = 1;
    }
    return t;
}

int BFS(){
    queue<tree> q;
    tree startT = turnPointToTree(startP);
    q.push(startT);
    chk[startT.x][startT.y][startT.dir] = true;

    while(q.empty()==false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y;
            int cd = q.front().dir; q.pop();

            if(endT.x==cx && endT.y==cy && endT.dir==cd){
                return result;
            }

            //이동
            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(cd==0){
                    if(nx>=0 && ny>=0 && nx<n && ny<n && moveBound1(nx,ny)==true && chk[nx][ny][0]==false){
                        chk[nx][ny][0] = true;
                        tree nt = {nx,ny,0};
                        q.push(nt);
                    }
                }else{
                    if(nx>=0 && ny>=0 && nx<n && ny<n && moveBound2(nx,ny)==true && chk[nx][ny][1]== false){
                        chk[nx][ny][1] = true;
                        tree nt = {nx,ny,1};
                        q.push(nt);
                    }
                }
            }

            //회전
            if(turnBound(cx,cy)==true){
                if(cd==0 && chk[cx][cy][1]==false){
                    chk[cx][cy][1] = true;
                    tree nt = {cx,cy,1};
                    q.push(nt);
                }

                if(cd==1 && chk[cx][cy][0]==false){
                    chk[cx][cy][0] = true;
                    tree nt = {cx,cy,0};
                    q.push(nt);
                }

            }
        }
        result++;
    }
    return -1;
}

int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='B'){
                point p = {i,j};
                startP.push_back(p);
                arr[i][j] = '0';
            }else if(arr[i][j]=='E'){
                point p = {i,j};
                endP.push_back(p);
                arr[i][j]='0';
            }
        }
    }

    //끝점처리
    endT = turnPointToTree(endP);
    int temp = BFS();

    if(temp==-1) cout<<0;
    else cout<<temp;

    return 0;
}
