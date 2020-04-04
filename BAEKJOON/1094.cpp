/*
[ 막대기 ]
https://www.acmicpc.net/problem/1094
*/

#include <cstdio>
#include <iostream>

using namespace std;

int arr[] = {64, 32, 16, 8, 4, 2, 1};
bool chk[7] = {false, };
int x;


int main(void){
    cin>>x;
    for(int i=0; i<7; i++){
        if(arr[i]<=x){
            x-=arr[i];
            chk[i] = true;
        }
    }

    int count = 0;

    for(int i=0; i<7; i++){
        if(chk[i] == true){
            count++;
        }
    }

    cout<<count;


    return 0;
}