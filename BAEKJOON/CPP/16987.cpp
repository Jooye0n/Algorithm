/*
계란계란
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct egg{
    int power;
    int weight;
};

int n;
egg arr[10];
bool chk[10];
int result;
int maxNum;


void found(int x){
    //x번째 계란 들고 나머지 다깨보기
    if(x == n){
        result = 0;
        for(int i=0; i<n; i++){
            if(chk[i] == true) result++;
        }
        if(maxNum<result) maxNum = result;
    }else{
        if(chk[x] == false){
            for(int i=0; i<n; i++){
                if(chk[i] == false && x!=i){
                    arr[x].power-=arr[i].weight;
                    arr[i].power-=arr[x].weight;
                    if(arr[x].power <=0) chk[x] = true;
                    if(arr[i].power <=0) chk[i] = true;//깨짐

                    found(x+1);

                    arr[x].power+=arr[i].weight;
                    arr[i].power+=arr[x].weight;
                    if(arr[x].power >0) chk[x] = false;
                    if(arr[i].power >0) chk[i] = false;

                }else if(chk[i] == true && x != i){
                    found(x+1);
                }
            }
        }else{
            found(x+1);
        }

    }
}

int main(){
    cin>>n;
    for(int i=0 ; i<n; i++){
        cin>>arr[i].power>>arr[i].weight;
    }

    found(0);
    cout<<maxNum;
    return 0;
}