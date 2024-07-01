/*
https://www.acmicpc.net/problem/1331
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
struct point{
    int x;
    int y;
};

queue<point> q;
int nx, ny;
int arr[7][7];
bool chk[7][7];

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,-2,-1,1,2};

int startX, startY;
bool resultFlag;

bool changeToCoord(string s){
    char alp = s[0];
    int num = s[1]-'0';

    nx = 7-num;
    ny = alp-'A'+1;

    if(nx<1 || ny<1 || nx>6 || ny>6) return false;
    else return true;
}

void getNightCanMove(int x, int y){
    //다음 이동으로 가능한 좌표만 q에 넣는다.

    for(int i=0; i<8; i++){
        int tx = x+dx[i];
        int ty = y+dy[i];

        if(tx>=1 && ty>=1 && tx<=6 && ty<=6 && chk[tx][ty]==false){
            point p = {tx,ty};
            q.push(p);
        }
    }
}

int main(){

    int cnt = 0;

    for(int i=1; i<=36; i++){
        string s;
        cin>>s;
        if(changeToCoord(s)==false){
            cout<<"Invalid";
            return 0;
        }else{
            if(i==1){
                startX = nx;
                startY = ny;

                chk[nx][ny] = true;
                cnt++;
                getNightCanMove(nx,ny);

            }else if(i==36){
                int size = q.size();
                while(size--){
                    
                    int cx = q.front().x;
                    int cy = q.front().y; q.pop();

                    if(cx==nx && cy==ny){
                        chk[nx][ny] = true;
                        cnt++;

                        for(int i=0; i<8; i++){
                            int tx = nx+dx[i];
                            int ty = ny+dy[i];
                            if(tx==startX && ty==startY && cnt==36){
                                resultFlag = true;
                            }
                        }
                    }
                }

            }else{
                int size = q.size();
                while(size--){
                    int cx = q.front().x;
                    int cy = q.front().y; q.pop();

                    if(cx==nx && cy==ny){
                        
                        chk[nx][ny] = true;
                        cnt++;
                        getNightCanMove(nx,ny);

                    }
                }
            }
        }
    }

    if(resultFlag==true) cout<<"Valid";
    else cout<<"Invalid";

    return 0;
}
