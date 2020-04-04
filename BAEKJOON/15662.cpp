/*
4
10101111
01111101
11001110
00000010
2
3 -1
1 1
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;
vector<vector<bool> >v(1001);
bool chk[1001];
int t,k;
int result;

void count12(){
    for(int i=1; i<=t; i++){
        if(v[i][0]==1) result++;
    }
}

void turn(int num, int dir){
    //num번 톱니 dir 방향으로 회전
    chk[num] = true;

    if(num==1){
        if(v[num][2]!=v[num+1][6] && chk[num+1]==false){
            turn(num+1,dir*-1);
        }
    }else if(num==t){
        if(v[num][6]!=v[num-1][2] && chk[num-1]==false){
            turn(num-1,dir*-1);
        }
    }else{
        if(v[num][2]!=v[num+1][6] && chk[num+1]==false){
            turn(num+1,dir*-1);
        }
        if(v[num][6]!=v[num-1][2] && chk[num-1]==false){
            turn(num-1,dir*-1);
        }
    }
    //나 자신 돌림.
    if(dir==-1){
        v[num].push_back(v[num][0]);
        v[num].erase(v[num].begin());
    }else if(dir==1){
        v[num].insert(v[num].begin(),v[num].back());
        v[num].pop_back();
    }
}

int main(){
    cin>>t;
    for(int i=1; i<=t; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            v[i].push_back(s[j]-'0');
        }
    }

    cin>>k;
    while(k--){
        memset(chk,false,sizeof(chk));
        int x, dir;
        cin>>x>>dir;
        turn(x,dir);
    }

    count12();
    cout<<result;

    return 0;
}