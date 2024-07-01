#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int n, result = -987987987;
string s;
bool oper[20];

int getResult(int x, int y, char op){
	if (op == '+') return x + y;
	else if (op == '-')return x - y;
	else if (op == '*') return x * y;
}

int calcul() {
	int cur = s[0] -'0';

	for (int i = 2; i < n; i+=2) {
		char op = s[i - 1];
		int next = s[i] -'0';
		if (oper[i + 1] == true) {
			cur = getResult(cur, getResult(s[i] - '0', s[i + 2] - '0', s[i + 1]), op);
			i+=2;
		}
		else {
			cur = getResult(cur, s[i] - '0', op);
		}
	}

	return cur;
}

void choice(int x) {
	if (x == n) {
		result = max(result, calcul());
	}
	else {
		if (x-2>=0 && oper[x - 2] == true) {
			oper[x] = false;
			choice(x + 2);
		}
		else {
			oper[x] = false;
			choice(x + 2);
			oper[x] = true;
			choice(x + 2);
		}
	}
}

int main() {
	cin >> n >> s;
	choice(1);
	cout << result;
	return 0;
}