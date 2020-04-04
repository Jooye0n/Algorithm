#include <bits/stdc++.h>
#define MAX 100002
using namespace std;
int n, m;
bool train[MAX][21];
set<long long> answer;

void pushSet() {
	//2진수 숫자로 바꿔서 set에 넣기
	for (int i = 1; i <= n; i++) {
		long long result = 0;
		int num = 1;
		for (int j = 1; j <= 20; j++) {
			if (train[i][j] == true) {
				result += num;
			}
			num *= 2;
		}
		answer.insert(result);
	}
}

void simul1(int num, int idx, int seat) {
	if (num == 1 && train[idx][seat] == false) train[idx][seat] = true;
	else if (num == 2 && train[idx][seat] == true) train[idx][seat] = false;
}

void simul2(int num, int idx) {
	if (num == 3) { //뒤로
		for (int i = 20; i > 1; i--) {
			if (train[idx][i] != train[idx][i - 1]) train[idx][i] = train[idx][i - 1];
		}
		train[idx][1] = false;
	}else{ //앞으로
		for (int i = 1; i < 20; i++) {
			if (train[idx][i] != train[idx][i + 1]) train[idx][i] = train[idx][i + 1];
		}
		train[idx][20] = false;
	}
}

int main() {
	cin >> n >> m;
	while(m--){
		int num, idx, seat;
		cin >> num;
		if (num == 1 || num == 2) {
			cin >> idx >> seat;
			simul1(num, idx, seat);
		}
		else {
			cin >> idx;
			simul2(num, idx);
		}
	}

	pushSet();
	cout << answer.size();
	return 0;
}