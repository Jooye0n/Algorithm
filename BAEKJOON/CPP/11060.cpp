/*
https://www.acmicpc.net/problem/11060

10
1 2 0 1 3 2 1 5 4 2

첫째 줄에 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 Ai (0 ≤ Ai ≤ 100)가 주어진다.
만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 -1을 출력한다.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int result[1001];

int main(){
    
    cin>>n; 
    for(int i=2; i<=n; i++){
        result[i] = 2000;
    }

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        for(int j=i+1; j<=i+arr[i]; j++){
            result[j] = min(result[j],result[i]+1);
        }
    }
    if(result[n]==2000) cout<<-1;
    else cout<<result[n];
    
    return 0;
}
