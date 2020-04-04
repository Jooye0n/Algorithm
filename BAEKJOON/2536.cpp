/*
7 6
8
1 2 1 2 2
2 1 1 5 1
6 7 3 7 6
7 2 1 2 6
3 3 2 6 2
4 5 6 5 1
5 1 5 7 5
8 3 5 6 5
2 1 7 4 
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct point{
    int x;
    int y;
};

struct Bus{
    point startP;
    point endP;
};

int num;
int n,m,k;
int chk[5001][4];//출발지와 겹치는 버스의 경우 2, 도착지와 겹치는 버스의 경우 3, 이미 체크된 버스의 경우 1
Bus bus[5001];
point beginP, destP;
queue<int> q;
int result = 987987987;
//전체적으로 수정 = 노선의 시작 부분이 노선의 끝보다 좌표가 클 수 있다.

void chkBus(){
    //출발지와 도착지 겹치는 버스 chk
    for(int i=1; i<=num; i++){
        if((bus[i].startP.x==beginP.x && bus[i].endP.x==beginP.x && min(bus[i].endP.y,bus[i].startP.y)<=beginP.y && max(bus[i].endP.y,bus[i].startP.y)>=beginP.y) 
        || (bus[i].startP.y==beginP.y && bus[i].endP.y==beginP.y && min(bus[i].endP.x,bus[i].startP.x)<=beginP.x && max(bus[i].endP.x,bus[i].startP.x)>=beginP.x)){
            chk[i][2] = true;
            chk[i][1] = true;
            q.push(i);//출발지와 겹치는 버스를 q에 넣음
        }
        if((bus[i].startP.x==destP.x && bus[i].endP.x==destP.x && min(bus[i].endP.y,bus[i].startP.y)<=destP.y && max(bus[i].endP.y,bus[i].startP.y)>=destP.y) 
        || (bus[i].startP.y==destP.y && bus[i].endP.y==destP.y && min(bus[i].startP.x,bus[i].endP.x)<=destP.x && max(bus[i].startP.x,bus[i].endP.x)>=destP.x)){
            chk[i][3] = true;
        }
    }
}

void chkBusToBus(int cx){
    //버스 x와 겹치는 버스 chk[1] && q에 push
    if(bus[cx].startP.x == bus[cx].endP.x){//cx 수평
        for(int i=1; i<=num; i++){
            if(bus[i].startP.x == bus[i].endP.x){//둘다 수평버스고
                if(bus[i].endP.x == bus[cx].endP.x){//둘의 x값 같으면서
                    if((bus[i].startP.y>=min(bus[cx].startP.y,bus[cx].endP.y) && bus[i].startP.y<=max(bus[cx].startP.y,bus[cx].endP.y)) 
                    || (bus[i].endP.y>=min(bus[cx].startP.y,bus[cx].endP.y) && bus[i].endP.y<=max(bus[cx].startP.y,bus[cx].endP.y))){
                        if(chk[i][1]==0 || chk[i][1]>chk[cx][1]+1){
                            chk[i][1] = chk[cx][1]+1;
                            q.push(i);
                        }
                    }
                }
            }else{//cx는 수평 i는 수직버스고
                if((bus[i].startP.y>=min(bus[cx].startP.y,bus[cx].endP.y) && bus[i].startP.y<=max(bus[cx].startP.y,bus[cx].endP.y))
                && (min(bus[i].startP.x,bus[i].endP.x)<=bus[cx].startP.x && max(bus[i].startP.x,bus[i].endP.x)>=bus[cx].startP.x)){
                    if(chk[i][1]==0 || chk[i][1]>chk[cx][1]+1){
                        chk[i][1] = chk[cx][1]+1;
                        q.push(i);
                    }
                }
            }  
        }
    }else{//cx 수직
        for(int i=1; i<=num; i++){
            if(bus[i].startP.y == bus[i].endP.y){//둘다 수직버스
                if(bus[i].startP.y == bus[cx].startP.y){//둘의 y값 같으면서
                    if((bus[i].startP.x>=min(bus[cx].endP.x,bus[cx].startP.x) && bus[i].startP.x<=max(bus[cx].endP.x,bus[cx].startP.x)) 
                    || (bus[i].endP.x>=min(bus[cx].endP.x,bus[cx].startP.x) && bus[i].endP.x<=max(bus[cx].endP.x,bus[cx].startP.x))){
                        if(chk[i][1]==0 || chk[i][1]>chk[cx][1]+1){
                            chk[i][1] = chk[cx][1]+1;
                            q.push(i);
                        }
                    }
                }
            }else{//cx는 수직 i는 수평
                if((bus[i].startP.x>=min(bus[cx].startP.x,bus[cx].endP.x) && bus[i].startP.x<=max(bus[cx].startP.x,bus[cx].endP.x))
                && (min(bus[i].startP.y,bus[i].endP.y)<=bus[cx].startP.y && max(bus[i].startP.y,bus[i].endP.y)>=bus[cx].startP.y)){
                    if(chk[i][1]==0 || chk[i][1]>chk[cx][1]+1){
                        chk[i][1] = chk[cx][1]+1;
                        q.push(i);
                    }
                }
            }    
        }
    }
}

void BFS(){
    //버스와 겹치는 버스를 q에 넣음
    //도착지와 겹치는 버스 나오면 끝
    while(q.empty()==false){
        int size = q.size();
        while(size--){
            int curBus = q.front(); q.pop();
            chkBusToBus(curBus);
        }
    }
}

void findResult(){
    for(int i=1; i<=num; i++){
        if(chk[i][1] != 0 && chk[i][3]==true){
            if(result>chk[i][1]) result = chk[i][1];
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<k; i++){
        cin>>num;
        cin>>bus[num].startP.x;
        cin>>bus[num].startP.y;
        cin>>bus[num].endP.x;
        cin>>bus[num].endP.y;
    }
    cin>>beginP.x>>beginP.y>>destP.x>>destP.y;
    chkBus();
    BFS();
    findResult();
    cout<<result;
    return 0;
}