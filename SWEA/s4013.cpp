#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


vector<vector<int> > v(5, vector<int>(8, 0));

bool chk[5];
int n;
int T;

void turn(int target, int dir){
    //targer을 dir로 돌린다.
    chk[target] = true;
    

    if(dir == 1){//시계
        int temp = v[target].back();
        v[target].erase(v[target].end()-1);
        v[target].insert(v[target].begin(),temp);
    }else if(dir == -1){// 반시계
        int temp = v[target][0];
        v[target].erase(v[target].begin());
        v[target].push_back(temp);
    }

    if(target == 1){
        if((chk[2] == false && dir == 1 && v[1][3] != v[2][6]) || (chk[2] == false && dir == -1 && v[1][1] != v[2][6])){
            turn(2,dir*-1);
        }
    }else if(target == 4){
        if((chk[3] == false && dir == 1 && v[4][7] != v[3][2]) || (chk[3] == false && dir == -1 && v[4][5] != v[3][2])){
            turn(3,dir*-1);
        }
    }else{
        if((chk[target-1] == false && dir == 1 && v[target][7] != v[target-1][2]) || 
        (chk[target-1] == false && dir == -1 && v[target][5] != v[target-1][2])){
            turn(target-1,dir*-1);
        }
        if((chk[target+1] == false && dir == 1 && v[target][3] != v[target+1][6]) || 
        (chk[target+1] == false && dir == -1 && v[target][1] != v[target+1][6])){
            turn(target+1,dir*-1);
        }
    }
}


int main(){
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n;

        for(int i=1; i<=4; i++){
            for(int j=0; j<8; j++){
                cin>>v[i][j];
            }
        }

        for(int i=0; i<n; i++){
            fill(&chk[0],&chk[5],false);
            int target, dir;
            cin>>target>>dir;
            turn(target,dir);
        }
        int rhq = 1;
        int total = 0;

        for(int i=1; i<=4; i++){
            if(v[i][0] == 1){
                total+=rhq;
            }
            rhq*=2;
        }

        cout<<'#'<<t<<' '<<total<<'\n';
    }
    return 0;
}