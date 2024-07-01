/*
만약 매 시간마다 개미 N개를 1씩 움직여서 시뮬레이팅하려고 하면 시간 내에 풀 수가 없습니다.
이 문제의 핵심은
1. 시간과 상관없이 개미가 막대 위에 놓여있는 순서는 변하지 않는다.(즉 개미 3, 개미 2, 개미 1 순서로 막대에 놓여있으면 서로간의 거리는 달라지더라도 놓여있는 순서는 유지된다.)
2. 두 개미가 부딪칠 때 경로를 반대로 가는 대신, 가던 길을 그대로 가되 ID만 서로 바꿔서 진행한다고 생각을 해도 상황은 똑같다. 즉 떨어지는 개미의 ID는 모르더라도 각 개미가 왼쪽, 오른쪽으로 언제 떨어지는지는 초기 상태부터 정해져있다.
이 두 가지를 염두해둔다면, k번째 떨어지는 개미가 왼쪽에서 떨어지는지 오른쪽에서 떨어지는지 알 수 있고 이를 알고나면 1번 성질에 의해 개미의 ID를 알 수 있습니다. 
*/

#include <stdio.h>
#include <algorithm>
#define F first
#define S second

using namespace std;
typedef pair<int, int> ANT; // distance with end, ID
ANT ant[100001];
int ID[100001]; // position이 항상 증가하는 순으로 들어오므로 ID만 저장해도 됨

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, l, k;
        scanf("%d %d %d", &N, &l, &k);
        for (int i = 0; i < N; i++) {
            int a, p;
            scanf("%d %d", &p, &a);
            ID[i] = a;

            if (a < 0) { // dir이 왼쪽인경우
                ant[i].F = p + 1;
                ant[i].S = a;
            }
            else { // dir이 오른쪽인경우
                ant[i].F = l - p + 1;
                ant[i].S = a;
            }
        }
        sort(ant, ant + N);
        int left = 0; // 왼쪽에서 떨어지는 개미의 수
        int right = 0; // 오른쪽에서 떨어지는 개미의 수

        for (int i = 0; i < k-1; i++) {
            if (ant[i].S < 0) // 왼쪽으로 가는 개미라면
                left++;
            else // 오른쪽으로 가는 개미라면
                right++;
        }
        if (k <= N - 1 && ant[k - 1].F == ant[k].F) { // ant[k-1], ant[k]가 동시에 떨어지는 상황. ant[k-1].S < 0, ant[k].S > 0
            printf("%d\n", min(ID[left], ID[N - right - 1])); // ID[left-1] : ant[k-1], ID[N-right-1] : ant[k]
            continue;
        }
        if (k > 1 && ant[k - 1].F == ant[k - 2].F) { // ant[k-2].S < 0, ant[k-1].S > 0
            printf("%d\n", max(ID[left - 1], ID[N - right - 1])); // ID[left-1] : ant[k-2], ID[N-right] : ant[k-1]
            continue;
        }
 
        if (ant[k - 1].S < 0) // 왼쪽에서 떨어지는 개미라면
            printf("%d\n", ID[left]);
        else
            printf("%d\n", ID[N - right - 1]);
    }
}