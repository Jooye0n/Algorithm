/*
[ 한윤정이 이탈리아에 가서 아이스크림을 사먹는데 ]
https://www.acmicpc.net/problem/2422


입력
첫째 줄에 정수 N과 M이 주어진다. N은 아이스크림 종류의 수이고, M은 섞어먹으면 안 되는 조합의 개수이다. 
아래 M개의 줄에는 섞어먹으면 안 되는 조합의 번호가 주어진다. 같은 조합은 두 번 이상 나오지 않는다. 
(1 ≤ N ≤ 200, 0 ≤ M ≤ 10,000)

출력
첫째 줄에, 가능한 방법이 총 몇 개 있는지 출력한다.

예제 입력 1 
5 3
1 2
3 4
1 3

예제 출력 1 
3
*/


#include <cstdio>
#include <iostream>

using namespace std;

int n, m;//N은 아이스크림 종류의 수이고, M은 섞어먹으면 안 되는 조합의 개수이다. 
int result[201] = {0, };
bool chk[201] = {false, };
bool map[201][201] = {0, };
int c = 0;


bool chkeat(int arr[]){
//가능하면 ture를 반환한다.
    if(map[result[0]][result[1]] == false && map[result[2]][result[1]] == false && map[result[0]][result[2]] == false)
    return true;
    else
    return false;
}

void selec(int x, int k){
    if(x == 3){
        if(chkeat(result) == true){
            // printf("%d%d%d\n", result[0], result[1],result[2]);
            c++;
    }
    }else{
        for(int i=k; i<=n; i++){
            if(chk[i] == false){
                result[x] = i;
                chk[i] = true;
                
                selec(x+1,i);
                chk[i] = false;
                
            }
        }
    }
}

int main(){

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        map[x][y] = true;
        map[y][x] = true;
    }

    selec(0, 1);
    cout<<c;
    return 0;
}