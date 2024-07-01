/*
https://www.acmicpc.net/problem/9205
*/

#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int T;
int n;

int fx, fy;
vector<point> v;
bool flag;
bool chk[101];

int getDistance(int x1, int x2, int y1, int y2){
    int dis = ( max(x1,x2)-min(x1,x2) ) + ( max(y1,y2)-min(y1,y2) );
    return dis;
}

void goToFestival(int x, int y){

    queue<point> q;
    point p = {x,y};
    q.push(p);

    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        if(getDistance(cx,fx,cy,fy)<=1000){
            flag = true;
            return;
        }

        for(int i=0; i<v.size(); i++){
            if(getDistance(cx,v[i].x,cy,v[i].y)<=1000 && chk[i] == false){
                chk[i] = true;
                q.push(v[i]);
            }
        }
    }
}

int main(){
    cin>>T;
    while(T--){
        v.clear();
        memset(chk,false,sizeof(chk));
        flag = false;

        cin>>n;
        int cx, cy;
        cin>>cx>>cy;

        for(int i=0; i<n; i++){
            point p;
            cin>>p.x>>p.y;
            v.push_back(p);
        }

        cin>>fx>>fy;
        goToFestival(cx,cy);
        
        if(flag == true) cout<<"happy\n";
        else cout<<"sad\n";
    }

    return 0;
}