/*
[ 뱀 ]
https://www.acmicpc.net/problem/3190

6
3
3 4
2 5
5 3
3
3 D
15 L
17 D

게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. 
X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct point{
    int x;
    int y;
};

int n;
int arr[101][101];//map
vector<point> v;
vector<pair<int,char> > oper;
int dir;

int result;

//0 - blank
//1 - snake
//2 - apple

int changeDir(int cur, char direc){
    int r;
    if(direc == 'D'){
        switch (cur)
        {
        case 0: r = 2;break;
        case 1: r = 3;break;
        case 2: r = 1;break;
        case 3: r = 0;break;
        }
    }else if(direc == 'L'){
        switch (cur)
        {
        case 0: r = 3;break;
        case 1: r = 2;break;
        case 2: r = 0;break;
        case 3: r = 1;break;
        }
    }
    return r;
}

int main(){
    cin>>n;
    int apple;
    cin>>apple;
    for(int i=0; i<apple; i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 2;
    }

    arr[1][1] = 1;
    point p = {1,1};
    v.push_back(p);
    dir = 0;


    int test;
    cin>>test;
    while(test--){
        int time;
        char tempdir;//time초 후에 바뀔 방향
        //현재 방향은 dir
        cin>>time>>tempdir;
        oper.push_back(make_pair(time,tempdir));
    }
        
    sort(oper.begin(), oper.end());

    int time;
    char tempdir;

    while(true){
        time = oper.front().first;
        tempdir = oper.front().second;
        
        if(oper.size() == 0) {
            time = n;
        }else{
            time-=result;
            oper.erase(oper.begin());
        } 
        while(time--){
            //time 만큼 dir 방향으로 직진
            point current = v.back();//머리
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];
            result++;
            if(nx>0 && ny>0 && nx<=n && ny<=n){
                
                //cout<<nx<<' '<<ny<<'\n';
                if(arr[nx][ny] == 0){//blank
                    arr[v.front().x][v.front().y] = 0;
                    v.erase(v.begin());
                }else if(arr[nx][ny] == 1){//snake
                    cout<<result;
                    return 0;
                }
                point next = {nx,ny};
                v.push_back(next);
                arr[nx][ny] = 1;
            }
            if(nx <= 0 || ny <= 0 || nx > n || ny > n){
                cout<<result;
                return 0;
            }
        }

        dir = changeDir(dir,tempdir);
    }
    cout<<result;
    
    return 0;
}
