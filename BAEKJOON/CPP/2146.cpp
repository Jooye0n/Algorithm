/*
다리만들기
https://www.acmicpc.net/problem/2146

10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

3
*/


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int n;
int groupNum = 1;
int minNum = 987987987;
point member[100];

int arr[101][101];
bool chk[101][101];
queue<point> q;
vector<int> v;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int getGroupMin(int start, int end){
    //chk[i][j]의 값이 더 작으면 안가고 더 크면 update
    int localMin = 0;

    while(q.empty() == false){
        int size = q.size();
        for(int j=0; j<size; j++){
            int cx = q.front().x;
            int cy = q.front().y;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(chk[nx][ny] == false && arr[nx][ny] == 0){
                        chk[nx][ny] = true;
                        point p = {nx,ny};
                        q.push(p);
                        
                    }else if(chk[nx][ny] == false && arr[nx][ny] == end){
                        //cout<<localMin<<' ';
                        return localMin;
                    }
                }
            }
        }

        localMin++;
    }

}

void found(int x, int k){
    if(x == 2){
        //v안의 두 그룹끼리의 최단거리 구하기
        fill(&chk[0][0],&chk[100][101],false);
        while(q.empty() == false)q.pop();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] == v[0]){
                    point p = {i,j};
                    chk[i][j] = true;
                    q.push(p);
                }
            }
        }
        int local = getGroupMin(v[0],v[1]);
        
        if(minNum>local){
            minNum = local;
        }

    }else{
        for(int i=k ;i<groupNum; i++){
            v.push_back(i);
            found(x+1,i+1);
            v.pop_back();
        }
    }
}

void BFS(int group){
    //그룹 만들어주기 arr[i][j] 에 그룹 num 적는다.
    while(q.empty() == false){
        int qx = q.front().x;
        int qy = q.front().y;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = qx+dx[i];
            int ny = qy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n && chk[nx][ny] == false && arr[nx][ny] == 1){
                chk[nx][ny] = true;
                arr[nx][ny] = group;
                point p = {nx,ny};
                q.push(p);
            }
        }
    }
}


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && chk[i][j] == false){
                chk[i][j] = true;
                arr[i][j] = groupNum;
                point p = {i,j};
                member[groupNum] = p;
                q.push(p);
                BFS(groupNum);
                groupNum++;//1 부터 하나씩 증가한다.
            }
        }
    }

    //그룹수(1-groupNum) 중에 2개 골라서 v에 담은 후 그 둘 사이의 최단 거리 알아내서 minNum update
    found(0,1);
    cout<<minNum;

    return 0;
}

