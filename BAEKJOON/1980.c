/*
[ 라비다 1980 ] - c코드 모법답안 분석용
비밀번호 자리수 N과 비밀번호 각 자리의 최대값이 입력될 때,
가능한 모든 좌물쇠 비밀번호를 오름차순으로 하나씩 출력하기.

입력
1//테스트 케이스
3//비밀번호 자리수
1 2 2//각 자리 최대값

출력
0 0 0
0 0 1
0 0 2
0 1 0
0 1 1
...
*/
#include <stdio.h>

int max[10];
int arr[10];


void calc(int pos, int n) {//pos는 현재 자리수가 된다.
    for(int i = 0; i <= max[pos]; i++) { // 각 자리수(pos)의 최댓값(max)까지 for문을 돌린다.
        arr[pos] = i; //그 자리수의 i 저장
        if(pos == n-1) { //마지막 자리라면 출력
            for(int j=0; j<n-1;j++) {
                printf("%d", arr[j]);
            }
            printf("%d\n", arr[n-1]);
        }else { //마지막 자리가 아니면 자리수 +1
            calc(pos + 1, n);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);//몇 번 실행할지 = t
    while(t--) {
        int n;
        scanf("%d", &n);//자리수 = n
        for(int i=0; i<n; i++) {
            scanf("%d", &max[i]);//입력받기
        }
        calc(0,n);//0부터 n까지 rec 실행하겠다.
    }
    return 0;
}