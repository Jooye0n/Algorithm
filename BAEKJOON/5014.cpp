/*
https://www.acmicpc.net/problem/5014

첫째 줄에 F, S, G, U, D가 주어진다. (1 ≤ S, G ≤ F ≤ 1000000, 0 ≤ U, D ≤ 1000000) 건물은 1층부터 시작하고, 가장 높은 층은 F층이다.
*/


#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int f,s,g,u,d;
int total;
queue<int> q;

bool chk[1000001];

void BFS(){
    q.push(s);
    chk[s] = true;

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            int c = q.front(); q.pop();
            if(c == g){
                cout<<total;
            }
            if(c+u<=f && chk[c+u] == false){
                chk[c+u] = true;
                q.push(c+u);
            }
            if(c-d>=1 && chk[c-d] == false){
                chk[c-d] = true;
                q.push(c-d);
            }
        }
        total++;
    }

}

int main(){
    cin>>f>>s>>g>>u>>d;
    BFS();
    if(chk[g] != true)
        printf("use the stairs");
    return 0;
}