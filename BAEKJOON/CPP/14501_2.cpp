#include <bits/stdc++.h>
using namespace std;
int n;
int day[16];
int money[16];
int dp[16];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> money[i];
	}

	for (int i = 1; i <= n; i++) {
		if(i+day[i]-1<=n) dp[i + day[i]-1] = max(*max_element(dp+1, dp + i)+money[i], dp[i + day[i] - 1]);
	}

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}