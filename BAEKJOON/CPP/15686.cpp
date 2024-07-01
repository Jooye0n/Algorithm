/*
치킨배달
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct point{
    int x;
    int y;
};

int arr[51][51];
int n, m;
int minNum = 987987987;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector<point> store;
vector<point> house;
vector<int> safeStore;


int calcul(point a, point b){
    int total = 0;

    if(a.x-b.x>=0) total+=a.x-b.x;
    else total+=b.x-a.x;

    if(a.y-b.y>=0) total+=a.y-b.y;
    else total+=b.y-a.y;

    return total;
}


int BFS(point p){
    //safeStore에 저장된 치킨집이 존재할 때, p집에서의 치킨거리의 합을 return

    int total = 987987987;

    for(int i=0; i<safeStore.size(); i++){
        int temp = calcul(store[safeStore[i]],p);
        if(total>temp) total = temp;
    }

    return total;
}

int getDirstance(){
    int total = 0;
    for(int i=0; i<house.size(); i++){
        total+=BFS(house[i]);
    }
    return total;
}

void found(int x, int k){
    if(x == m){
        //남길 치킨집 다골랐다.
        int temp = getDirstance();
        if(minNum>temp){
            minNum = temp;
        }

    }else{
        for(int i=k; i<store.size(); i++){
            safeStore.push_back(i);
            found(x+1,i+1);
            safeStore.pop_back();
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                point p = {i,j};
                house.push_back(p);
            }else if(arr[i][j] == 2){
                point p = {i,j};
                store.push_back(p);
            }
        }
    }

    //남길 치킨집 경우의 수 고르고
    found(0,0);
    
    //이 중 최소값 찾아 return
    cout<<minNum;
    return 0;
}