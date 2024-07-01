/*
https://www.acmicpc.net/problem/2309
20
7
23
19
10
15
25
8
13
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int total;

int temp[2];

void printAll(int x, int y){
    //x와 y제외하고 프린트
    sort(arr,arr+9);

    for(int i=0; i<9; i++){
        if(arr[i]==x || arr[i]==y) continue;
        cout<<arr[i]<<'\n';
    }
}

void found(int x, int k){
    if(x == 2){
        if(total-arr[temp[0]]-arr[temp[1]] == 100){
            printAll(arr[temp[0]], arr[temp[1]]);
            exit(0);
        }
    }else{
        for(int i=k; i<9; i++){
            temp[x] = i;
            found(x+1,i+1);
        }
    }
}

int main(){
    for(int i=0; i<9; i++){
        cin>>arr[i];
        total+=arr[i];
    }

    found(0,0);

    return 0;
}