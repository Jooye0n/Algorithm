/*
맥주마시면서 걸어가기
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cmath>

using namespace std;
struct point{
    int x,y;
};

int n;
bool chk[101];//편의점 체크
vector<point> v;//편의점
point house, festival;

int getDistance(int x, int x1, int y, int y1){
    return abs(x-x1)+abs(y-y1);
}

string BFS(){
    queue<point> q;
    q.push(house);
    
    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();
        if(getDistance(cx,festival.x,cy,festival.y)<= 1000) return "happy";

        for(int i=0; i<v.size(); i++){
            if(chk[i]) continue;
            if(getDistance(cx,v[i].x, cy,v[i].y) > 1000) continue;
            chk[i] = true;
            point temp = {v[i].x, v[i].y};
            q.push(temp);
        }
    }

    return "sad";
}

int main(){
    int T; cin>>T;
    while(T--){
        cin>>n;
        memset(chk,false,sizeof(chk));
        v.clear();
        cin>>house.x>>house.y;

        for(int i=0;i<n; i++){
            int x,y; cin>>x>>y;
            point temp  = {x,y};
            v.push_back(temp);
        }

        cin>>festival.x>>festival.y;
        cout<<BFS()<<'\n';
    }
    return 0;
}