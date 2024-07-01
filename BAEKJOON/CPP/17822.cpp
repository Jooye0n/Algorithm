/*
https://www.acmicpc.net/problem/17822

입력
첫째 줄에 N, M, T이 주어진다.
둘째 줄부터 N개의 줄에 원판에 적힌 수가 주어진다. i번째 줄의 j번째 수는 (i, j)에 적힌 수를 의미한다.
다음 T개의 줄에 xi, di, ki가 주어진다.

4 4 1
1 1 2 3
5 2 4 2
3 1 3 5
2 1 3 2
2 0 1
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n,m,t;
int result;
vector<vector<int> > v(51);

void foundSameNumber(){
    //인접하면서 같은 수 찾는다.
    //있으면, 지운다. 없으면 전체 평균 작은수 +1 큰수 -1
    bool chk[51][51] = {0, };
    bool flag = false;
    int tempTotal = 0;
    int tempCnt = 0;

    //같은 원판에서 인접
    for(int i=1; i<=n; i++){
        for(int j=0; j<m-1; j++){
            if(v[i][j] == 0) continue; 

            if(j != 0 && v[i][j] == v[i][j-1]){//이전꺼와같음
                chk[i][j] = true; chk[i][j-1] = true;
            }

            if(v[i][j] == v[i][j+1]){//다음꺼와같음
                chk[i][j] = true; chk[i][j+1] = true;
            }

            if(j == 0 && v[i][j] == v[i][m-1]){
                    chk[i][j] = true; chk[i][m-1] = true;
            }

        }
    }

    //다른 판에서 인접
    for(int i=0; i<m; i++){
        for(int j=1; j<=n; j++){

            if(v[j][i] == 0) continue; 

            if(j != 1){
                if(v[j][i] == v[j-1][i]){
                    chk[j][i] = true;
                    chk[j-1][i] = true;
                }
            }

            if(j != n){
                if(v[j][i] == v[j+1][i]){
                    chk[j][i] = true;
                    chk[j+1][i] = true;
                }
            }
        }
    }

    //지우기
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] !=0){
                tempTotal+=v[i][j];
                tempCnt++;
                if(chk[i][j] == true){
                    flag = true;
                    v[i][j] = 0;
                }
            }
        }
    }


    if(flag == false && tempTotal !=0){//인접한 같은 수 없음
        int div = tempTotal % tempCnt;
        tempTotal /= tempCnt;
        if(div == 0){
            for(int i=1; i<=n; i++){
                for(int j=0; j<m; j++){
                    if(v[i][j] == 0) continue;

                    if(v[i][j] > tempTotal) v[i][j]--;
                    else if(v[i][j] <  tempTotal) v[i][j]++;
                }
            }
        }else{
            for(int i=1; i<=n; i++){
                for(int j=0; j<m; j++){
                    if(v[i][j] == 0) continue;

                    if(v[i][j] > tempTotal) v[i][j]--;
                    else if(v[i][j] <=  tempTotal) v[i][j]++;
                }
            }
        }

    }
}

int calculTotal(){
    int result =0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] != 0) result += v[i][j];
        }
    }
    return result;
}

void turnVector(int a, int b, int c){

    int tuenCnt = c % m;

    for(int i=1; i<=n; i++){
        if(i % a == 0){
            if(b == 0){//시계
                for(int j=0; j<tuenCnt; j++){
                    v[i].insert(v[i].begin(), v[i].back());
                    v[i].pop_back();
                }
            }else if(b == 1){//반시계
                for(int j=0; j<tuenCnt; j++){
                    v[i].push_back(v[i].front());
                    v[i].erase(v[i].begin());
                }
            }
        }
    }

    foundSameNumber();
}
int main(){
    cin>>n>>m>>t;
    for(int i=1; i<=n; i++){
        for(int j=0 ;j<m; j++){
            int temp;
            cin>>temp;
            v[i].push_back(temp);
        }
    }

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        turnVector(a,b,c);
    }

    cout<<calculTotal();
    return 0;
}

