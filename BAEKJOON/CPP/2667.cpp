/*
[ 단지번호 붙이기 ]
//DFS로 풀어볼게요~
https://www.acmicpc.net/problem/2667
입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

예제 입력 1 
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
예제 출력 1 
3
7
8
9
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<int> v[26];
vector<int> result;
bool chk[26][26];
int arr[26][26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int total;

void DFS(int x, int y){
    chk[x][y] = true;
    total++;

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(0<=nx && nx<n && 0<=ny && ny<n){
            if(arr[nx][ny] == 1 && chk[nx][ny] == false)
                DFS(nx,ny);
        }
        
    }

}

int main(){

    cin>>n;
    for(int i=0;i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size();j++){
            arr[i][j] = s[j]-'0';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && chk[i][j] == false){
                total = 0;
                DFS(i,j);
                result.push_back(total);
            }
        }
    }

    sort(result.begin(), result.end());

    cout<<result.size()<<'\n';
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<'\n';
    }

    return 0;
}
