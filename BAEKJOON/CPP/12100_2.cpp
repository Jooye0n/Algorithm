#include <bits/stdc++.h>
using namespace std;

int n;
int result;
int arr[20][20];
stack<int> st;
bool flag;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void getResult() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > result) result = arr[i][j];
		}
	}
}

void move(int i, int j) {
	if (arr[i][j] > 0) {
		int val = arr[i][j];
		arr[i][j] = 0;

		if (st.empty()) st.push(val);
		else if (!flag && st.top() == val) {
			st.top() += val;
			flag = true;
		}
		else {
			st.push(val);
			flag = false;
		}
	}
}

void gotoDir(int x) {
	//x방향으로 밀기
	if (x == 1) {
		//x == 1 (<-)
		for (int i = 0; i < n; i++) {
			flag = false;
			for (int j = 0; j < n; j++) {
				move(i, j);
			}
			if (st.empty()) continue;
			for (int j = st.size()-1; !st.empty(); j--) {
				arr[i][j] = st.top();
				st.pop();
			}
		}
	}
	else if (x == 0) {
		//-> 방향
		for (int i = 0; i < n; i++) {
			flag = false;
			for (int j = n-1; j >=0; j--) {
				move(i, j);
			}
			if (st.empty()) continue;
			for (int j = n - st.size(); !st.empty(); j++) {
				arr[i][j] = st.top();
				st.pop();
			}
		}
	}
	else if (x == 2) {
		//아래로
		for (int i = 0; i < n; i++) {
			flag = false;
			for (int j = n - 1; j >= 0; j--) {
				move(j, i);
			}
			if (st.empty()) continue;
			for (int j = n - st.size(); !st.empty(); j++) {
				arr[j][i] = st.top();
				st.pop();
			}
		}
	}
	else if (x == 3) {
		//위로
		for (int i = 0; i < n; i++) {
			flag = false;
			for (int j = 0; j<n; j++){
				move(j, i);
			}
			if (st.empty()) continue;
			for (int j = st.size() - 1; !st.empty(); j--) {
				arr[j][i] = st.top();
				st.pop();
			}
		}
	}
}

void BackT(int x) {
	if (x == 5) {
		getResult();
	}else{
		int temp[20][20]; memcpy(temp, arr, sizeof(arr));
		for (int i = 0; i < 4; i++) {
			gotoDir(i);
			BackT(x + 1);
			memcpy(arr, temp, sizeof(arr));
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	BackT(0);
	cout << result;
	return 0;
}