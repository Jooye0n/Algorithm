/*
https://www.acmicpc.net/problem/16235
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10][10];//현재 땅
int plusArr[10][10];//겨울에 추가될 양분
vector<int> tree[10][10];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int n,k,year;//k는 나무 수
int result;

void springAndSummer(){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(tree[i][j].empty()==true) continue;
            sort(tree[i][j].begin(),tree[i][j].end());
            int plusCnt = 0;

            for(int t=0; t<tree[i][j].size(); t++){
                if(arr[i][j]>=tree[i][j][t]){
                    arr[i][j] -= tree[i][j][t];
                    tree[i][j][t]++;
                }else{
                    plusCnt += tree[i][j][t]/2;
                    tree[i][j].erase(tree[i][j].begin()+t); 
                    t--;
                }
            }

            arr[i][j] += plusCnt;

            

        }
    }
}

void fallAndWinter(){

    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            for(int t=0; t<tree[i][j].size(); t++){
                if(tree[i][j][t] % 5 == 0){
                    for(int d=0; d<8; d++){
                        int nx = i+dx[d];
                        int ny = j+dy[d];

                        if(nx>=0 && ny>=0 && nx<n && ny<n){
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }

            arr[i][j] += plusArr[i][j];
        }
    }
}

void countResult(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result += tree[i][j].size();
        }
    }
}

int main(){
    cin>>n>>k>>year;

    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = 5;
            cin>>plusArr[i][j];
        }
    }

    for(int i=0; i<k; i++){
        int x, y, z;
        cin>>x>>y>>z;
        tree[x-1][y-1].push_back(z);
    }

    while(year--){
        springAndSummer();
        fallAndWinter();
    }

    countResult();
    cout<<result;
    return 0;
}