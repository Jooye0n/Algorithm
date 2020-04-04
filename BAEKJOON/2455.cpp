/*
[ 지능형 기차 ]
https://www.acmicpc.net/problem/2455

입력
각 역에서 내린 사람 수와 탄 사람 수가 빈칸을 사이에 두고 
첫째 줄부터 넷째 줄까지 역 순서대로 한 줄에 하나씩 주어진다. 

출력
첫째 줄에 최대 사람 수를 출력한다.  
*/

#include <cstdio>
#include <iostream>

using namespace std;

int arr[4] = {0, };
int n,m;



int main(){

    cin>>n>>m;
    arr[0] = m;
    int maxnum = m;

    for(int i=1; i<4; i++){
        cin>>n>>m;
        arr[i] = arr[i-1]+m-n;
        if(maxnum<arr[i])
            maxnum = arr[i];
    }
    cout<<maxnum;

    return 0;
}