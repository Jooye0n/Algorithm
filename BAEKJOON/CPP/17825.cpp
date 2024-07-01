/*
https://www.acmicpc.net/problem/17825
*/

#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

struct point{
    int mapNum;//말의 map번호
    int idx;//map[mapNum]안에서 말의 idx
    bool fin;//도착 여부
};

int finIdx[4] = {21,23,17,13};//맵마다 도착의 idx

int map[4][24] = {
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0},
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40,0},//19-23
    {0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40,0},//13-17
    {0,2,4,6,8,10,13,16,19,25,30,35,40,0}//9-13
};

int subIdx[4] = {0,19,13,9};//겹치는 부분의 시작점

int dice[10];
vector<int> v;//말 4개의 순서
point arr[4];//말 4개의 정보
int answer;//최종 정답

int samePlace(int x, int dx){
    //x말을 dx만큼 이동
    //잡히면 return -1; 
    //안잡히면 이동 후 return 얻은 점수

    int mapNum = arr[x].mapNum;
    int mapIdx = arr[x].idx + dx;
    
    if(arr[x].fin == true) return -1;//이미 도착이면 이동 불가능

    if(mapNum == 0 && mapIdx % 5 == 0 && mapIdx !=0){
        //맵이 바뀌는 경우
        if(mapIdx == 15) mapNum = 1;
        else if(mapIdx == 10) mapNum = 2;
        else if(mapIdx == 5) mapNum = 3;
    }

    for(int i=0; i<4; i++){//잡힘의 경우 이동 불가능
        if(arr[i].fin == true) continue;//이미 도착한 말은 무시
        if(arr[i].mapNum == mapNum && arr[i].idx == mapIdx){
            return -1;
        }
    }

    if(mapNum != 0 && mapIdx>=subIdx[mapNum]){//겹치는 구간일 경우(123)
        int sub = mapIdx - subIdx[mapNum];
        for(int i=0; i<4; i++){
            if(arr[i].fin == true) continue;//이미 도착한 말은 무시
            if(arr[i].mapNum == 0) continue;//0번 맵 무시

            int tmp = arr[i].idx - subIdx[arr[i].mapNum];
            if(tmp == sub) return -1;
        }
    }

    if(finIdx[mapNum]-1 == mapIdx){//도착 바로 전 idx는 모두 겹친다.
        for(int i=0; i<4; i++){
            if(finIdx[arr[i].mapNum] -1 == arr[i].idx) return -1;
        }
    }

    if(finIdx[mapNum]<mapIdx){//도착을 넘어서면 도착으로
        arr[x].fin = true;
        mapIdx = finIdx[mapNum];
    }

    arr[x].mapNum = mapNum;
    arr[x].idx = mapIdx;
    
    return map[mapNum][mapIdx];
}

void move(){
    //10번의 이동 후 answer update
    int result = 0;
    memset(arr,0,sizeof(arr));

    for(int i=0; i<10; i++){
        int cx = v[i];//현재 움직일 말
        int dx = dice[i];//현재 움직일 칸 수

        int temp = samePlace(cx,dx);
        if(temp == -1) return;//잡히는 경우 or 이미 도착인 경우라면 더이상 볼 필요 없다.
        else result += temp;
    }
    if(answer<result) answer = result;
}

void choice(int x){
    if(x == 10){
        move();
    }else{
        for(int i=0; i<4; i++){
            v.push_back(i);
            choice(x+1);
            v.pop_back();
        }
    }
}
int main(){
    for(int i=0; i<10; i++){
        cin>>dice[i];
    }

    choice(0);
    cout<<answer;
    return 0;
}