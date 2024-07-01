/*
https://www.acmicpc.net/problem/17281
2
4 0 0 0 0 0 0 0 0
4 0 0 0 0 0 0 0 0
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[51][10];//i 이닝 j 선수
int n;//이닝 수
int result;
bool chkOrder[10];
vector<int> hitOrder;

void DFS(int x, int k, int cnt){
    if(x == n+1){
        result = max(result,cnt);
    }else{
        //x번째 이닝 시작선수 k 획득 점수 cnt
        int outCnt = 0;
        bool map[4] = {0,0,0,0};

        while(true){
            //k번째 선수 공 친다. 
            map[0] = true;

            switch(arr[x][hitOrder[k]]){
                case 0:
                outCnt++;
                map[0] = false;
                break;

                case 1:
                if(map[3] == true) cnt++;
                
                map[3] = map[2];
                map[2] = map[1];
                map[1] = map[0];

                map[0] = false;
                break;

                case 2:
                if(map[3] == true) cnt++;
                if(map[2] == true) cnt++;
                
                map[3] = map[1];
                map[2] = map[0];

                map[0] = false;
                map[1] = false;
                break;

                case 3:
                if(map[3] == true) cnt++;
                if(map[2] == true) cnt++;
                if(map[1] == true) cnt++;

                map[3] = map[0];

                map[0] = false;
                map[1] = false;
                map[2] = false;
                break;

                case 4:
                if(map[3] == true) cnt++;
                if(map[2] == true) cnt++;
                if(map[1] == true) cnt++;
                if(map[0] == true) cnt++;

                map[0] = false;
                map[1] = false;
                map[2] = false;
                map[3] = false;
                break;
            }
            if(outCnt==3) break;
            else k = (k+1)%9;
        }
        DFS(x+1,(k+1)%9,cnt);
    }
}


void choice(int x){
    //1은 이미 정해져있으므로 8명의 순열 구한다.
    if(x == 10){
        DFS(1,0,0);
    }else if(x == 4){
        hitOrder.push_back(1);
        choice(x+1);
        hitOrder.pop_back();
    }else{
        for(int i=2; i<=9; i++){
            if(chkOrder[i] == false){
                hitOrder.push_back(i);
                chkOrder[i] = true;
                choice(x+1);
                hitOrder.pop_back();
                chkOrder[i] = false;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=9; j++){
            cin>>arr[i][j];
        }
    }

    //타순 순열 구하기
    choice(1);
    cout<<result;
    return 0;
}