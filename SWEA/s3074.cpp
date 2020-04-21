#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
long long n, m;
long long arr[MAX];
 
bool countTime(long long x) {
    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += x / arr[i];
    }
    return result >= m;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(arr, 0, sizeof(arr));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        long long start = 1;
        long long end = *max_element(arr, arr + n + 1) * m ;
 
        while (start + 1 < end) {
            long long mid = (start + end) / 2;
            if (countTime(mid) == true) end = mid;
            else start = mid;
        }
 
        cout << '#' << t << ' ' << end << '\n';
    }
    return 0;
}