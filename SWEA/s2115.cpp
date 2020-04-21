#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int arr[10][10];
bool chk[10][10] = { false, };
int result;
 
void findMax(int x, int k, int cnt, int rst, int total, int* tempResult, vector<int> v) {
    //v에서 모든 수의 조합 중 최대 구하기 but, <=c
    if (x == cnt) {
        *tempResult = max(rst, *tempResult);
    }
    else {
        for (int i = k; i < v.size(); i++) {
            if(total + v[i] <= c) findMax(x + 1, i + 1, cnt, rst + v[i] * v[i], total + v[i], tempResult, v);
        }
    }
}
 
void choiceM(int x, int y, int cnt, int tempResult) {
    //x,y 부터 m개 고르기
    if (y + m > n) return;
    for (int i = y; i < y + m; i++) {
        if (chk[x][i] == true) return;
    }
 
    vector<int> v;
    for (int i = y; i < y + m; i++) {
        chk[x][i] = true;
        v.push_back(arr[x][i]);
    }
 
    int temp = tempResult;
    for (int i = 1; i <= m; i++) {
        findMax(0,0,i,temp,0,&tempResult,v);
    }
 
    if(cnt == 1) result = max(result, tempResult);
    else if (cnt == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (chk[i][j] == false) {
                    choiceM(i, j, 1, tempResult);
                }
            }
        }
    }
 
    for (int i = y; i < y + m; i++) {
        chk[x][i] = false;
    }
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        result = 0;
        memset(chk, false, sizeof(chk));
        cin >> n >> m >> c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                choiceM(i, j, 0, 0);
            }
        }
 
        printf("#%d %d\n", t, result);
    }
    return 0;
}