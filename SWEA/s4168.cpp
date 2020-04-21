#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[25];
int s[25];
long long result;
bool resultChk[25];
bool chk[25];
 
void makeC(int x, long long S, int P) {
    //S = 만족도, P = 가격
    if (P > n) return;
    if (S > result) {
        result = S;
        memcpy(resultChk, chk, sizeof(chk));
    }
    for (int i = x; i < m; i++) {
        chk[i] = true;
        makeC(i+1, S + s[i], P + p[i]);
        chk[i] = false;
    }
}
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(resultChk, false, sizeof(resultChk));
        result = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> p[i] >> s[i];
        }
        makeC(0, 0, 0);
        cout << '#' << t << ' ';
        for (int i = 0; i < m; i++) {
            if (resultChk[i] == true) {
                cout << i << ' ';
            }
        }
        cout << result << '\n';
    }
    return 0;
}