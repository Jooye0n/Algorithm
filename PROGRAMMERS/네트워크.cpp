#include <string>
#include <vector>
#include <queue>
#include <iostream>

//그룹 수 구하기
using namespace std;
bool chk[201];
vector<vector<int>> v;
int N;

void BFS(int x){
    queue<int> q;
    q.push(x);
    chk[x] = true;
    
    while(q.empty() == false){
        int cx = q.front(); q.pop();
        for(int i=0; i<N; i++){
            if(v[cx][i] == 1 && chk[i] == false){
                chk[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N=n;
    v = computers;
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(chk[i] == false){
            BFS(i);
            answer++;
        }
    }
    
    return answer;
}