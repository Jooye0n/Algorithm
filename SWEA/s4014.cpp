#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[20][20];
int result;
 
int countCul(int x) {
    //세로선 검사
    int idx = 0;
    int cnt = 1;
    while (idx < n - 1) {
        int sub = arr[idx][x] - arr[idx + 1][x];
        if (sub == 0) {
            idx++;
            cnt++;
        }
        else if (sub == -1) {//더 높아짐
            if (cnt >= k) {
                idx++;
                cnt = 1;
            }
            else return 0;
        }
        else if (sub == 1) {
            if (idx + k >= n ) return 0;
            for (int i = 2; i <= k; i++) {
                if (arr[idx + i][x] != arr[idx + 1][x]) return 0;
            }
            cnt = 0;
            idx += k;
        }
        else return 0;
    }
    return 1;
}
 
int countRow(int x) {
    //가로선 검사
    int idx = 0;
    int cnt = 1;
    while (idx < n - 1) {
        int sub = arr[x][idx] - arr[x][idx+1];
        if (sub == 0) {
            idx++;
            cnt++;
        }
        else if (sub == -1) {//더 높아짐
            if (cnt >= k) {
                idx++;
                cnt = 1;
            }
            else return 0;
        }
        else if (sub == 1) {
            if (idx + k >= n ) return 0;
            for (int i = 2; i <= k; i++) {
                if (arr[x][idx+i] != arr[x][idx+1]) return 0;
            }
            cnt = 0;
            idx += k;
        }
        else return 0;
    }
    return 1;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        result = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
 
        for (int i = 0; i < n; i++) {
            result += countCul(i) + countRow(i);
        }
 
        printf("#%d %d\n", t, result);
    }
    return 0;
}