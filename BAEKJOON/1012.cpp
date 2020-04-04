/*
[ 유기농 배추 ]
https://www.acmicpc.net/problem/1012

입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 
그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 
그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.

예제 입력 1 
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
예제 출력 1 
5
1

*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m,k;
int test;
int result;
queue<pair<int,int>> q;
int arr[51][51];
bool chk[51][51];

// void DFS(int x, int y){
//     chk[x][y] = true;

//     for(int i=0; i<4; i++){
//         int nx = x+dx[i];
//         int ny = y+dy[i];
        
//         if(nx>=0 && nx<n && ny>=0 && ny<m && chk[nx][ny] == false && arr[nx][ny] == 1){
//             DFS(nx,ny);
//         }
//     }
// }

void BFS(int x, int y){
    pair<int,int> p = make_pair(x,y);
    q.push(p);
    chk[x][y] = true;

    while(q.empty() == false){
        int cx = q.front().first();
        int cy = q.front().second();
        
    }
}

int main(){
    cin>>test;

    while(test--){
        result = 0;
        while( !q.empty() ) q.pop();//q.clear();
        fill(&arr[0][0], &arr[50][51],0);
        fill(&chk[0][0],&chk[50][51],false);

        cin>>n>>m>>k;
        
        
        for(int i=0; i<k; i++){
            int a, b;
            cin>>a>>b;

            arr[a][b] = 1;
        }

        //DFS실행하면서 숫자 세기
        //성공
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(chk[i][j] == false && arr[i][j] == 1){
        //             DFS(i,j);
        //             result++;
        //         }
        //     }
        // }

        //BFS실행하면서 숫자 세기
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(chk[i][j] == false && arr[i][j] == 1){
                    BFS(i,j);
                    result++;
                }
            }
        }

        cout<<result<<'\n';


    }

    return 0;
}
