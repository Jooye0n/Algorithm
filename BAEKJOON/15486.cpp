/*
https://www.acmicpc.net/problem/15486
*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct Day{
    int during;
    int pay;
};

Day arr[1500001];
int result[1500001];
int maxNum[1500001];

int n;

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d %d",&arr[i].during,&arr[i].pay);
        if(i+arr[i].during-1<=n){
            result[i+arr[i].during-1] = max(result[i+arr[i].during-1],maxNum[i-1]+arr[i].pay);
        }
        maxNum[i] = max(maxNum[i-1],result[i]);
    }

    printf("%d",maxNum[n]);

    return 0;
}