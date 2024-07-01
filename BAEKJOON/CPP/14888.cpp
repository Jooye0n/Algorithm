/*
[ 연산자 끼워넣기 ]
https://www.acmicpc.net/problem/14888

첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 
둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 
차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다. 

2
5 6
0 0 1 0

30
30
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[11];
vector<int> oper;
int tempoper[12];
bool chk[11];

int maxNum =-987987987;
int minNum = 987987987;

void found(int x){
    if(x == oper.size()+1){
        int tempresult = arr[0];

        for(int i=1; i<n; i++){
            switch (tempoper[i])
            {
            case 1://+
                tempresult+=arr[i];
                break;
            
            case 2://-
                tempresult-=arr[i];
                break;

            case 3://*
                tempresult*=arr[i];
                break;

            case 4:///
                tempresult/=arr[i];
                break;
            }
        }

        if(tempresult>maxNum){
            maxNum = tempresult;
        }

        if(tempresult<minNum){
            minNum = tempresult;
        }

    }else{
        for(int i=0; i<oper.size(); i++){
            if(chk[i] == false){
                tempoper[x] = oper[i];
                chk[i] = true;
                found(x+1);
                chk[i] = false;
            }
        }

    }
}

int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=4; i++){
        int temp;
        cin>>temp;
        for(int j=0; j<temp; j++){
            oper.push_back(i);
        }
    }


    found(1);//tempoper에 값을 채우고 계산까지 완료

    cout<<maxNum<<'\n'<<minNum;




    return 0;
}
