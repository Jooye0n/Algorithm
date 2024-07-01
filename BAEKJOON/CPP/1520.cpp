#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
int input[501][501];
int dp[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
int dfs(int row, int col){
    if (dp[row][col] != -1) return dp[row][col]; //값이 이미 있는 경우
    if (row < 0 || row >= n || col < 0 || col >= m) return 0; // 없는 좌표
    if (row == 0 && col == 0) return 1; // 기저 사례

    dp[row][col] = 0;

    for (int i = 0; i < 4; i++){ // 4 way search
        int nextX = row + dx[i];
        int nextY = col + dy[i];
        
        if (input[nextX][nextY] > input[row][col])
            dp[row][col] += dfs(nextX, nextY);
    }
    return dp[row][col];
}
 
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &input[i][j]);
 
    memset(dp, -1, sizeof(dp));
    printf("%d", dfs(n - 1, m - 1));
    return 0;
} 
