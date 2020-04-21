#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[25];
int s[25];
int result = 0;
 
void makeC(int x, int S, int P) {
    //S = 만족도, P = 가격
    if (P > n) return;
    result = max(S, result);
    for (int i = x; i < m; i++) {
        makeC(i + 1, S + s[i], P + p[i]);
    }
}
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        result = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> p[i] >> s[i];
        }
        makeC(0, 0, 0);
        printf("#%d %d\n", t, result);
    }
    return 0;
}