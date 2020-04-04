/*
[ 한수 ]
https://www.acmicpc.net/problem/1065

입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

예제 입력 1 
110
예제 출력 1 
99
예제 입력 2 
1
예제 출력 2 
1
예제 입력 3 
210
예제 출력 3 
105
예제 입력 4 
1000
예제 출력 4 
144
*/

#include <cstdio>
#include <iostream>

using namespace std;

int n;

bool count(int x){
    //x가 한수이면 true, 아니면 false 반환
    int temp = n;
    int arr[4];

    arr[1] = x/100;
    arr[2] = (x - arr[1]*100)/10;
    arr[3] = x % 10;


    if(arr[1] != 0){
        if(arr[2]-arr[1] != arr[3] - arr[2])
            return false;
        else{
        return true;
        }
    }
}

int main(){
    cin>>n;
    int c = 99;

     if(n<100){
         cout<<n;
     }else{
         if(n == 1000){
             n = 999;
         }

         for(int i=100; i<=n; i++){
            if(count(i) == true)
                c++;
        }

        cout<<c;
     }

    return 0;
}
