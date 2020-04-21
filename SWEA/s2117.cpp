#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int money[25];
int arr[20][20];
int maxHouse;
 
void makeTable() {
    for (int i = 1; i <= 25; i++) {
        money[i] = i * i + (i - 1) * (i - 1);
    }
}
 
void makeCase(int x, int y, int k) {
    bool chk[20][20] = { false, };
    memset(chk, false, sizeof(chk));
    int cntHouse = 0;
    int idx = 1;
 
    for (int i = y - k + 1; i < y; i++) {
        for (int j = 0; j < idx; j++) {
            if (i >= 0 && x - j >= 0 && i < n && x - j < n) {
                if (chk[x - j][i] == false && arr[x - j][i] == 1) {
                    chk[x - j][i] = true;
                    cntHouse++;
                }
            }
            if (i >= 0 && x + j >= 0 && i < n && x + j < n) {
                if (chk[x + j][i] == false && arr[x + j][i] == 1) {
                    chk[x + j][i] = true;
                    cntHouse++;
                }
            }
        }
        idx++;
    }
 
    for (int i = y; i < y + k; i++) {
        for (int j = idx - 1; j >= 0; j--) {
            if (i >= 0 && x - j >= 0 && i < n && x - j < n) {
                if (chk[x - j][i] == false && arr[x - j][i] == 1) {
                    chk[x - j][i] = true;
                    cntHouse++;
                }
            } 
            if (i >= 0 && x + j >= 0 && i < n && x + j < n) {
                if (chk[x + j][i] == false && arr[x + j][i] == 1) {
                    chk[x + j][i] = true;
                    cntHouse++;
                }
            }
        }
        idx--;
    }
       
    if (cntHouse * m - money[k] >= 0) {
        maxHouse = max(maxHouse, cntHouse);
    }
}
 
void isItReasonable(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            makeCase(i, j, x);
        }
    }
}
 
int main() {
    makeTable();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        maxHouse = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = n + 1; i > 0; i--) {
            isItReasonable(i);
        }
        printf("#%d %d\n", t, maxHouse);
    }
    return 0;
}