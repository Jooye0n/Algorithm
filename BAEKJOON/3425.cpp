/*
DUP
MUL
NUM 2
ADD
END
3
1
10
50
*/

#include <stack>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 1000000000
using namespace std;
vector<pair<string, int> > v;
int n;

void error() {
	printf("ERROR\n");
}

void goStack(int x) {
	//전체 계산 후 프린트까지 진행하는 함수
	stack<int> s;
	s.push(x);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first.compare("NUM") == 0) {
			s.push(v[i].second);
		}
		else if (v[i].first.compare("POP") == 0) {
			if (s.empty() == true) {
				error();
				return;
			}
			else s.pop();
		}
		else if (v[i].first.compare("INV") == 0) {
			if (s.empty() == true) {
				error();
				return;
			}
			else {
				int temp = s.top(); s.pop();
				s.push(temp * -1);
			}
		}
		else if (v[i].first.compare("DUP") == 0) {
			if (s.empty() == true) {
				error();
				return;
			}
			else {
				int temp = s.top();
				s.push(temp);
			}
		}
		else if (v[i].first.compare("SWP") == 0) {
			if (s.size() < 2) {
				error();
				return;
			}
			else {
				int temp = s.top(); s.pop();
				int temp2 = s.top(); s.pop();

				s.push(temp);
				s.push(temp2);
			}
		}
		else if (v[i].first.compare("ADD") == 0) {
			if (s.size() < 2) {
				error();
				return;
			}
			else {
				int temp = s.top(); s.pop();
				int temp2 = s.top(); s.pop();
				long long rst = temp + temp2;
				if (abs(rst) > MAX) {
					error();
					return;
				}
				else s.push(temp + temp2);
			}
		}
		else if (v[i].first.compare("SUB") == 0) {
			if (s.size() < 2) {
				error();
				return;
			}
			else {
				int temp = s.top(); s.pop();
				int temp2 = s.top(); s.pop();
				long long rst = temp2 - temp;
				if (abs(rst) > MAX) {
					error();
					return;
				}
				s.push(temp2 - temp);
			}
		}
		else if (v[i].first.compare("MUL") == 0) {
			if (s.size() < 2) {
				error();
				return;
			}
			else {
				int temp = s.top(); s.pop();
				int temp2 = s.top(); s.pop();
				long long rst = temp * temp2;
				if (abs(rst) > MAX) {
					error();
					return;
				}
				s.push(temp2 * temp);
			}
		}
		else if (v[i].first.compare("DIV") == 0) {
			if (s.size() < 2) {
				error();
				return;
			}
			else {
				int temp = s.top(); s.pop();
				int temp2 = s.top(); s.pop();
				if (temp2 == 0) {
					error();
					return;
				}
				long long result = abs(temp2) / abs(temp);
				if (abs(result) > MAX) {
					error();
					return;
				}
				if ((abs(temp) == temp && abs(temp2) != temp2) || (abs(temp) != temp && abs(temp2) == temp2)) {
					s.push(result * -1);
				}
				else {
					s.push(result);
				}
			}
		}
		else if (v[i].first.compare("MOD") == 0) {
			if (s.size() < 2) {
				error();
				return;
			}
			else {
				int temp = s.top(); s.pop();
				int temp2 = s.top(); s.pop();
				if (temp2 == 0) {
					error(); return;
				}
				long long result = abs(temp2) % abs(temp);
				if (result > MAX) {
					error();
					return;
				}
				if (abs(temp2) != temp2) {
					s.push(result * -1);
				}
				else {
					s.push(result);
				}
			}
		}
	}


	if (s.size() == 1) {
		printf("%d\n", s.top());
	}
	else {
		error();
	}
}

int main() {
	while (true) {
		v.clear();
		while (true) {
			string s; cin >> s;
			int N = 0;
			if (s.compare("NUM") == 0) {
				cin >> N;
			}
			else if (s.compare("END") == 0) break;
			else if (s.compare("QUIT") == 0) return 0;
			v.push_back(make_pair(s, N));
		}

		vector<int> num;
		cin >> n;
		while (n--) {
			int temp; cin >> temp;
			num.push_back(temp);
		}

		for (int i = 0; i < num.size(); i++) {
			goStack(num[i]);
		}
	}
	return 0;
}