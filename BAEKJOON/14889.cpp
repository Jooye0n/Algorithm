/*
[ 스타트와 링크 ]
https://www.acmicpc.net/problem/14889
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int m;
int arr[21][21];

int sel[21];//스타트팀
int unsel[21];//링크팀
bool chk2[21];

int result = 987987987;
int funTotal = 0;

void getSum(int x, int k,int array[],int total[]){
    //배열이 주어지면 능력치를 구한다. 
    if(x == 2){
        funTotal+=arr[total[0]][total[1]];
        funTotal+=arr[total[1]][total[0]];
    }else{
        for(int i=k; i<m; i++){
            total[x] = array[i];
            getSum(x+1,i+1,array,total);
        }
    }

}

void found(int x, int k){
    if(x == m){
        int j=0;
        for(int i=1; i<=n; i++){
            if(chk[i] == false){
                unsel[j++] = i;
            }
        }

        int total[21];

        funTotal = 0;
        getSum(0,0,unsel,total);
         int a = funTotal;


        funTotal = 0;
        getSum(0,0,sel,total);
        int b = funTotal;

        int temp = max(a,b)-min(a,b);
        if(temp<result){
            result = temp;
        }

    }else{
        for(int i=k; i<=n; i++){
            sel[x] = i;
            found(x+1,i+1);
        }
    }
}

int main(){
    cin>>n;
    m = n/2;

    for(int i=1 ; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    found(0,1);
    cout<<result;
    return 0;
}