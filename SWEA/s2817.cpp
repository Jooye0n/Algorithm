#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[20];
int result;
 
void DFS(int x, int total) {
    if (total > k) return;
    if (total == k) {
        result++;
        return;
    }
 
    for (int i = x; i < n; i++) {
        DFS(i + 1, total + arr[i]);
    }
}
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        result = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
 
        DFS(0, 0);
        printf("#%d %d\n", t, result);
    }
    return 0;
}