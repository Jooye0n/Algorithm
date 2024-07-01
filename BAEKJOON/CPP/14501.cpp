/*
다빈이의 소망 퇴사
https://www.acmicpc.net/problem/14501
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct day{
    int during;
    int money;
};

int n;
day arr[16];
int result[16];

//int total;//돈

// void found(int x, int total){
//     if(x == n){
//         if(maxTotal<total){
//             maxTotal = total;
//         }
//     }else{
//         for(int i=x; i<n; i++){
//             if(x+arr[i].during+(i-x)<=n){
//                 found(x+arr[i].during+(i-x),total+arr[i].money);
//             }
//             found(x+1,total);
//         }

//     }
// }

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i].during>>arr[i].money;
    }

    for(int i=0; i<n; i++){
        if(i+arr[i].during-1<=n-1){
            result[i+arr[i].during-1] = max(result[i+arr[i].during-1], arr[i].money + *max_element(result,result+i));
        }
    }

    cout<<*max_element(result,result+n);
    
    return 0;
}