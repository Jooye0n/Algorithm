/*
[ 보물상자 비밀번호 ]
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo

입력
2
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8

1
24 16
044D3EBA6A647B2567A91D0E

#4 5667473

츨력
#1 503
#2 55541
#3 334454
#4 5667473
#5 182189737

[제약 사항]
 
N은 4의 배수이고, 8이상 28이하의 정수이다. (8 ≤ N ≤ 28)       
N개의 숫자는 각각 0이상 F이하로 주어진다. (A~F는 알파벳 대문자로만 주어진다.)
K는 생성 가능한 수의 개수보다 크게 주어지지 않는다.

[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 숫자의 개수 N과 크기 순서 K가 주어 진다.
그 다음 줄에는 16진수 0~F 숫자가 공백 없이 N개 주어진다.

 

[출력]

출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace  std;
int t;
int main(){
    cin>>t;
    for(int test=1; test<=t; test++){
        int n, k;
        cin>>n>>k;
        vector<int> v;

        for(int i=0; i<n; i++){
            char c; cin>>c;
            int temp;
            if(c >='0' && c<='9'){
                temp = c-'0';
            }else if(c>='A' && c<='F'){
                temp = c-'A'+10;
            }
            v.push_back(temp);
        }

        int div = n/4;//회전수 및 자리수

        for(int i=0; i<div; i++){
            v.push_back(v[i]);
        }

        vector<int> result;

        for(int i=0; i<div; i++){//회전 수
            //16진수->10진수로 바꾸어 숫자 하나씩
            for(int s=i; s<n+i; s+=div){//첫 번째 자리 나타내게 된다. 0 6 12 18 

                int total = 0;

                for(int k=div-1; k>=0; k--){//543210 
                    int number = v[s+(div-k)];//현재 자리 

                    for(int a=0; a<k; a++){
                        number*=16;
                    }

                    total+=number;
                    
                }

                //printf("total:%d\n",total);
                if(find(result.begin(), result.end(),total) == result.end())//없으면,
                    result.push_back(total);
            }
        }
        
        sort(result.begin(), result.end(),greater<int> ());
        cout<<'#'<<test<<' '<<result[k-1]<<'\n';
    }


    return 0;
}
