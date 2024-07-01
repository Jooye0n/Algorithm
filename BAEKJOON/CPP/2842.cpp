#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

char arr[50][50];
int piro[50][50];
bool chk[50][50];
int n;
vector<int> v;//피로도 중복없이 sort된 vector

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int leftNum, rightNNum;
int cntTemp;

void DFS(int x, int y){
    //x y부터 피로도가 left보다 크거나 같고 right보다 작거나 같다
    chk[x][y] = true;

    if(arr[x][y] == 'K') cntTemp++;

    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<n && chk[nx][ny]==false && piro[nx][ny]>=leftNum && piro[nx][ny]<=rightNNum){
            DFS(nx,ny);
        }
    }
}

int main(){

    int startX, startY;
    int result = 1000000;//1,000,000
    int cntHouse = 0;

    cin>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<n; j++){
            arr[i][j] = s[j];
            if(arr[i][j] == 'P'){
                startX = i;
                startY = j;
            }else if(arr[i][j] == 'K'){
                cntHouse++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>piro[i][j];
            v.push_back(piro[i][j]);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    int j=0;

    for(int i=0; i<v.size(); i++){
        while(true){
            cntTemp = 0;
            leftNum = v[j]; 
            rightNNum = v[i];
            memset(chk,false, sizeof(chk));

            if(piro[startX][startY]>=leftNum && piro[startX][startY]<=rightNNum)
                DFS(startX,startY);
            if(cntTemp != cntHouse) break;
            result = min(result,v[i]-v[j]);
            j++;

        }
    }
    
    cout<<result;
    return 0;
}