/*
https://www.acmicpc.net/problem/13460

5 5
#####
#..B#
#.#.#
#RO.#
#####

첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 
다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. 
'.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.
입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

char arr[11][11];
int n,m;
point hole;

int dx[4] = {-1,1,0,0};//상 하 좌 우
int dy[4] = {0,0,-1,1};

void printAll(){
    cout<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<' ';
        }cout<<'\n';
    }cout<<'\n';
}

point gotoDir(point p, int dir){
    //p에 있는 공을 dir으로 기울이는 경우 결과값 point return
    point result;

    int cx = p.x;
    int cy = p.y;
 
    int flag = false;//다른 구슬을 만났는가의 여부
    char temp = arr[p.x][p.y];

    while(true){

        int nx = cx+dx[dir];
        int ny = cy+dy[dir];

        if(arr[nx][ny] == '#'){

            if(flag == true){
                result.x = cx-dx[dir];
                result.y = cy-dy[dir];
            }else{
                result.x = cx;
                result.y = cy;
            }

            break;

        }else if(arr[nx][ny] == '.'){
            cx = nx;
            cy = ny;
        }else if(arr[nx][ny] == '0'){
            result.x = nx;
            result.y = ny;
            break;
        }else{//다른 구슬
            flag = true;
            cx = nx;
            cy = ny;
        }
    }
    
    arr[p.x][p.y] = '.';
    arr[result.x][result.y] = temp;
    return result;
    
}

void turnArr(int x, point red, point blue){
    if(x>10){
        cout<<-1;
        exit(0);
    }else if(red.x == hole.x && red.y == hole.y && (blue.x != hole.x || blue.y != hole.y)){//빨간 구슬만 hole에 들어갔으면,
        cout<<x;
        exit(0);
    }else{
        for(int i=0; i<4; i++){//상하좌우로 따져보기
            // cout<<red.x<<' '<<red.y<<'\n';
            // cout<<blue.x<<' '<<blue.y<<'\n';

            point newRed = gotoDir(red,i);
            point newBlue = gotoDir(blue,i);
            
            turnArr(x+1,newRed,newBlue);

            arr[red.x][red.y] = arr[newRed.x][newRed.y];                
            if(red.x != newRed.x || red.y != newRed.y)
                arr[newRed.x][newRed.y] = '.';

            arr[blue.x][blue.y] = arr[newBlue.x][newBlue.y];
            if(blue.x !=newBlue.x || blue.y != newBlue.y)
                arr[newBlue.x][newBlue.y] = '.';

        }

        exit(0);
    }
}


int main(){
    cin>>n>>m;
    point red, blue;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'B') { blue.x = i; blue.y = j;}
            else if(arr[i][j] == 'R') { red.x = i; red.y = j;}
            else if(arr[i][j] == '0') { hole.x = i; hole.y = j;}
        }
    }

    turnArr(0,red,blue);
    return 0;
}
