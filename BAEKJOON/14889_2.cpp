#include <bits/stdc++.h>
using namespace std;
int n, result = 987987987;
int arr[20][20];
bool chk[20];

vector<int> start;
vector<int> link;

pair<int, int> s;
pair<int, int> l;

int r1, r2;

void getPower(int x, int k) {
	if (x == 2) {
		r1 += arr[s.first][s.second] + arr[s.second][s.first];
		r2 += arr[l.first][l.second] + arr[l.second][l.first];
	}
	else {
		for (int i = k; i < start.size(); i++) {
			if (x == 0) {
				s.first = start[i];
				l.first = link[i];
			}
			else if (x == 1) {
				s.second = start[i];
				l.second = link[i];
			}

			getPower(x + 1, i+1);
		}
	}
}

void makeTeam(int x, int k) {
	if (x == n / 2) {
		r1 = 0; r2 = 0;
		start.clear();
		link.clear();
		for (int i = 0; i < n; i++) {
			if (chk[i] == true) start.push_back(i);
			else link.push_back(i);
		}

		getPower(0, 0);
		result = min(abs(r1 - r2), result);
		
	}
	else {
		for (int i = k; i < n; i++) {
			chk[i] = true;
			makeTeam(x + 1, i + 1);
			chk[i] = false;
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

	makeTeam(0,0);
	cout << result;
	return 0;
}