#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
int n,B;
int result;
vector<int> v;
void DFS(int x, int total) {
    if (total >= B) {
        if (total < result) result = total;
        return;
    }
    else {
        for (int i = x; i < n; i++) {
            DFS(i + 1, total + v[i]);
        }
    }
}
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> B;
        v.clear();
        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
            v.push_back(temp);
        }
        result = MAX;
        DFS(0, 0);
        printf("#%d %d\n", t, result-B);
    }
    return 0;
}