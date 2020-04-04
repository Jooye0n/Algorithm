#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int T;
int arr[17][17];
bool chk[16];
bool chk2[16];
vector<int> result;

int cho[16];//뽑기놀이 저장용

int sub = 987987987;
int total;

void calc(vector<int> v, int x){
    //주어진 배열 마다 모든 합 계산하여 total 
    //v중에서 2개 뽑기 전부한 후에 다더하면 된다.
    if(x == 2){
        int a = cho[0];
        int b = cho[1];
        total+=arr[a][b];


    }else{
        for(int i=0 ;i<v.size(); i++){
            if(chk2[i] == false){
                chk2[i] = true;
                cho[x] = v[i];
                calc(v,x+1);
                chk2[i] = false;
            }
        }
    }
}

void choose(int x, int k){
    //n개중 n/2개 골라서 result에 넣기
    if(x == n/2){
        vector<int>temp;
        for(int i=0; i<n; i++){
            if(chk[i] == false){
                temp.push_back(i);
            }
        }
        

        total = 0;
        calc(temp,0);
        int a = total; 

        total = 0;
        calc(result,0);
        int t = total>a
        if(sub>t)sub = t;

    }else{
        for(int i=k; i<n; i++){
            if(chk[i] == false){
                chk[i] = true;
                result[x] = i;
                choose(x+1,i+1);
                chk[i] = false;
            }
        }
    }
}

int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        sub = 987987987;
        fill(&arr[0][0],&arr[16][17],0);

        cin>>n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }

        result.resize(n/2);

        choose(0,0);
        printf("#%d %d\n",i,sub);
    }
    return 0;
}
