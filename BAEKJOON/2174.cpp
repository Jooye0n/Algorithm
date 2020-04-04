/*
입력
첫째 줄에 두 정수 A, B가 주어진다. 다음 줄에는 두 정수 N, M이 주어진다. 다음 N개의 줄에는 각 로봇의 초기 위치(x, y좌표 순) 및 방향이 주어진다. 다음 M개의 줄에는 각 명령이 명령을 내리는 순서대로 주어진다. 각각의 명령은 명령을 내리는 로봇, 명령의 종류(위에 나와 있는), 명령의 반복 회수로 나타낸다. 각 명령의 반복 회수는 1이상 100이하이다.

출력
첫째 줄에 시뮬레이션 결과를 출력한다. 문제가 없는 경우에는 OK를, 그 외의 경우에는 위의 형식대로 출력을 한다. 만약 충돌이 여러 번 발생하는 경우에는 가장 먼저 발생하는 충돌을 출력하면 된다.

예제 입력 1 
5 4
2 2
1 1 E
5 4 W
1 F 7
2 F 7
예제 출력 1 
Robot 1 crashes into the wall
*/

#include <cstdio>
#include <iostream>

using namespace std;

struct Robot{
    int x;
    int y;
    int d;
};

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

int n,m;
int k,t;//로봇 수와 명령 수

Robot robot[101];

void goLeft(int id, int num){
    int temp = num % 4;
    while(temp--){
        robot[id].d = (robot[id].d + 3) % 4;
    }
}

void goRight(int id, int num){
    int temp = num % 4;
    while(temp--){
        robot[id].d = (robot[id].d + 1) % 4;
    }
}

int gostrict(int id, int num){
    //벽 충돌은 -1
    //다른 로봇과 충돌은 로봇 num 
    //정상 시뮬 0 return 

    int cx = robot[id].x;
    int cy = robot[id].y;
    int cd = robot[id].d;

    while(num--){
        int nx = cx+dx[cd];
        int ny = cy+dy[cd];

        if(nx<=0 || ny<=0 || nx>n || ny>m) return -1;
        
        for(int i=1; i<=k; i++){
            if(i == id) continue;
            if(robot[i].x == nx && robot[i].y == ny) return i;
        }

        cx = nx;
        cy = ny;
    }

    robot[id].x = cx;
    robot[id].y = cy;
    return 0;
}

int main(){
    cin>>m>>n;
    cin>>k>>t;

    for(int i=1; i<=k; i++){
        char temp;
        cin>>robot[i].y>>robot[i].x>>temp;
        robot[i].x = n - robot[i].x + 1;

        if(temp == 'N') robot[i].d = 0;
        else if(temp == 'E') robot[i].d = 1;
        else if(temp == 'S') robot[i].d = 2;
        else if(temp == 'W') robot[i].d = 3;
    }

    while(t--){
        int id, num;
        char dir;
        int result = 0;
        cin>>id>>dir>>num;

        if(dir == 'L'){
            goLeft(id,num);
        }else if(dir == 'R'){
            goRight(id,num);
        }else if(dir == 'F'){
            result = gostrict(id,num);
        }

        if(result == 0) continue;
        else if(result > 0){
            cout<<"Robot "<<id<<" crashes into robot "<<result<<'\n';
            return 0;
        }else if(result == -1){
            cout<<"Robot "<<id<<" crashes into the wall"<<'\n';
            return 0;
        }
    }

    cout<<"OK"<<'\n';
    return 0;
}