/*
https://www.acmicpc.net/problem/1043
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n,m;
int k;
bool chkPerson[51];
bool chkParty[51];
vector<int> party [51]; //이 파티에 포함된 사람
vector<int> person [51]; //이 사람이 포함된 파티
queue<int> q;

void BFS(){
    while(q.empty() == false){
        int cx = q.front(); q.pop(); // 사람 하나 당
        for(int i=0; i<person[cx].size(); i++){
            int idx = person[cx][i];
            if(chkParty[idx] == false){
                for(int j=0; j<party[idx].size(); j++){
                    int pIdx = party[idx][j];
                    if(chkPerson[pIdx] == false){
                        chkPerson[pIdx] = true;
                        q.push(pIdx);
                    }
                }
                chkParty[idx] = true;
            }
        }
    }
}

int main(){
    int cnt = 0;
    cin>>n>>m;
    cin>>k;
    while(k--){
        int num; cin>>num;
        chkPerson[num] = true;
        q.push(num);
    }

    for(int i=1; i<=m; i++){
        int num; cin>>num;
        while(num--){
            int temp; cin>>temp;
            party[i].push_back(temp);
            person[temp].push_back(i);
        }
    }
    
    BFS();

    for(int i=1; i<=m; i++){
        if(chkParty[i] == false) cnt++;
    }
    cout<<cnt;
    return 0;
}