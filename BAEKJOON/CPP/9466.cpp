#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int arr[MAX];//연결관계 저장
int n;//전체 학생 수
bool done[MAX];//탐색이 완료됨
bool chk[MAX];//DFS를 위한 chk
int result = 0; //팀을 이룬 학생 수

void foundCycle(int x) {

	chk[x] = true; //방문
	int next = arr[x];

	if (chk[next] == false) foundCycle(next); //다음꺼 방문 안했으면 방문
	else if (done[next] == false) { //다음꺼 탐색 완료 안됐는데 방문했으면 cycle
		for (int i = next; i != x; i = arr[i]) result++;
		result++;
	}

	//탐색 완료임을 표시
	done[x] = true;
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n;
		result = 0; 

		memset(done, false, sizeof(done));
		memset(chk, false, sizeof(chk));

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		
		for (int i = 1; i <= n; i++) {
			if (done[i] == false) {
				foundCycle(i);
			}
		}

		cout << n - result << '\n';
	}
	return 0;
}