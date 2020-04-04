/*
[ 슈퍼 마리오 ]
https://www.acmicpc.net/problem/2851

입력
총 10개의 줄에 각각의 버섯의 점수가 주어진다. 이 값은 100보다 작거나 같은 양의 정수이다. 버섯이 나온 순서대로 점수가 주어진다.

출력
첫째 줄에 마리오가 받는 점수를 출력한다. 만약 100에 가까운 수가 2개라면 (예: 98, 102) 마리오는 큰 값을 선택한다.

*/
#include <stdio.h>
#include <iostream>

using namespace std;

int arr[10];
int sum = 0;

int main(){
    for(int i=0;i<10; i++){
        cin>>arr[i];
        int temp = sum;
        sum+=arr[i];
        if(sum>=100){
            if(100-temp>=sum-100){
                cout<<sum;
                return 0;
            }else{
                cout<<temp;
                return 0;
            }
        }
    }

    cout<<sum;


    return 0;
}