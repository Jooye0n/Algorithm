#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

#define MAC 10002
#define STAR 10001
#define MAX 300000000
#define N 10005

using namespace std;
struct point{
    int x, w;
};

int n,m;//v,e
vector<pair<int, int> > arr[N];
int num[2];
int dist[2];
int result[N][2];
bool chk[N];

void BFS(int dest, int def){
    //dest에서 집까지 dis 이하면 result에 거리 더한다.
    //아니면 result에 MAX 더한다.
    queue<int> q;
    int dis = dist[def];

    for(int i=0; i<arr[dest].size(); i++){
        int idx = arr[dest][i].first;
        q.push(idx);
        result[idx][def] = 0;
    }

    while(q.empty() == false){
        int cx = q.front(); q.pop();
        for(int i=0; i<arr[cx].size(); i++){

            int idx = arr[cx][i].first;
            int d = arr[cx][i].second;
            int next = result[cx][def]+d;

            if(d > 0 && next<=dis && result[idx][def]>next){
                result[idx][def] = next;
                q.push(idx);
            }
        }
    }
}

int foundResult(){
    //result return
    int res = MAX;
    for(int i=1; i<=n; i++){
        if(result[i][0] == 0 || result[i][1] == 0 ) continue;
        res = min(res,result[i][0]+result[i][1]);
    }
    return res == MAX ? -1 : res;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        result[i][0] = MAX;
        result[i][1] = MAX;
    }

    for(int i=0; i<m; i++){
        int x,y,w; cin>>x>>y>>w;
        arr[x].push_back(make_pair(y,w));
        arr[y].push_back(make_pair(x,w));
    }

    cin>>num[1]>>dist[1];
    for(int i=0; i<num[1]; i++){
        int x; cin>>x;
        arr[MAC].push_back(make_pair(x,0));
        arr[x].push_back(make_pair(MAC,0));
    }

    cin>>num[0]>>dist[0];
    for(int i=0; i<num[0]; i++){
        int x; cin>>x;
        arr[STAR].push_back(make_pair(x,0));
        arr[x].push_back(make_pair(STAR,0));
    }

    BFS(MAC, 1);
    BFS(STAR, 0);
    cout<<foundResult();
    return 0;
}