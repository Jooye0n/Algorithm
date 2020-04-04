/*
[ 나이트의 이동 ]
https://www.acmicpc.net/problem/7562

3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int dx[8] = {-1, 1, -1, 1, 2, 2, -2, -2};
int dy[8] = {2, 2, -2, -2, -1, 1, -1, 1};
int test;

            int n= 0;
            int result = 0;
            bool chk[301][301];

            int destx, desty;//이동하려는 칸
            int curx, cury;//현재 칸

            queue<point> q;



void BFS(){
            while(q.empty() == false){
            int size = q.size();
            result++;
            
            for(int i=0; i<size; i++){
                point current = q.front(); q.pop();

                if(current.x == destx && current.y == desty){
                    cout<<result-1<<'\n';
                    return;
                }
                
                for(int j=0; j<8; j++){
                    int nx = current.x+dx[j];
                    int ny = current.y+dy[j];

                    if(nx>=0 && ny>=0 && nx<n && ny<n &&chk[nx][ny]== false){
                        point next = {nx, ny};
                        q.push(next);
                        chk[nx][ny] = true;
                    }
                }
            }
        }
}

int main(){
    cin>>test;
    while(test--){
        result = 0;
        fill(&chk[0][0], &chk[300][301], false);
        while(q.empty() == false) q.pop();

        cin>>n;
        cin>>curx>>cury;
        cin>>destx>>desty;

        point p = {curx,cury};
        q.push(p);
        chk[curx][cury] = true;

        BFS();


    }

    return 0;
}
