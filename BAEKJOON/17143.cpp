/*
낚시왕

첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)
둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 
상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다. 
(r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.
*/

/*
1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.

낚시왕이 오른쪽으로 한 칸 이동한다.
낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
상어가 이동한다.
*/


#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Shark{
    int x;
    int y;
    int s;//속력
    int d;//이동방향 1위 2아래 3오른 4왼쪽
    int z;//크기

    bool die;//살아있는가
};

Shark shark[10002];

int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1};
int h,w,n;
int total;

void sharkMove(){
    //초당 상어의 이동
    //모든 상어 for문 돌면서, 살아있는 상어들은 s만큼 d방향으로 이동.
    //경계일 경우 방향 바뀌기
    //크기가 큰 상어가 나머지 상어를 모두 잡아먹는다.

    int chk[101][101] = {0, };//상어가 있다면 상어의 idx적어둠
    
    for(int i=1; i<=n; i++){
        
        if(shark[i].die == false){
            int length = shark[i].s;
            //cout<<shark[i].x<<' '<<shark[i].y<<' '<<'>'<<' ';
            if(shark[i].d == 1 || shark[i].d == 2) length = length % (2*h-2);
            else if(shark[i].d == 3 || shark[i].d == 4) length = length % (2*w-2);

            
            while(length--){
                int cx = shark[i].x;
                int cy = shark[i].y;

                int nx = cx+dx[shark[i].d];
                int ny = cy+dy[shark[i].d];

                if(nx>0 && ny>0 && nx<=h && ny<=w){
                    shark[i].x = nx;
                    shark[i].y = ny;

                }else{
                    if(shark[i].d == 1) shark[i].d = 2;
                    else if(shark[i].d == 2) shark[i].d = 1;
                    else if(shark[i].d == 3) shark[i].d = 4;
                    else if(shark[i].d == 4) shark[i].d = 3;

                    nx = cx+dx[shark[i].d];
                    ny = cy+dy[shark[i].d];

                    if(nx>0 && ny>0 && nx<=h && ny<=w){
                        shark[i].x = nx;
                        shark[i].y = ny;
                    }
                }
            }
            //cout<<shark[i].x<<' '<<shark[i].y<<'\n';
            //이동완료

            //만약 이미 상어가 있으면 대결
            //크기작은상어 die 큰상어 적기

            //없으면 그냥 적기
            if(chk[shark[i].x][shark[i].y] > 0){
                int idx = chk[shark[i].x][shark[i].y];
                int winner = shark[idx].z>shark[i].z ? idx : i;
                int loser = shark[idx].z>shark[i].z ? i : idx;
                chk[shark[i].x][shark[i].y] = winner;
                shark[loser].die = true;
            }else if(chk[shark[i].x][shark[i].y] == 0){
                chk[shark[i].x][shark[i].y] = i;
            }
        }
    }
}

int found(int person){
    //x초에 잡은 상어 크기 return
    //전체 상어 돌면서 상어의 y == person 이면서 x값이 가장 작은 상어의 크기 return 후 상어 죽이기
    int minX = 987987987;
    int idx;

    for(int i=1; i<=n; i++){
        if(shark[i].die == false){
            if(shark[i].y == person && minX > shark[i].x){
                idx = i;
                minX = shark[i].x;
            }
        }
    }

    if(minX == 987987987){
        //상어가 없음
        return 0;
    }else{
        shark[idx].die = true;//죽이기
        return shark[idx].z;
    }
}

int main(){
    cin>>h>>w>>n;
    for(int i=1; i<=n; i++){
        cin>>shark[i].x>>shark[i].y>>shark[i].s>>shark[i].d>>shark[i].z;
    }

    int result = 0;

    for(int i=1; i<=w; i++){
        result+=found(i);//초당 낚시왕의 위치에 따른 상어잡기
        sharkMove();
    }

    cout<<result;
    return 0;
}
