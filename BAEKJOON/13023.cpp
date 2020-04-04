#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<int> arr[2000];
bool chk[2000];

bool dfs(int depth, int n) {
	if (depth == 5) {
		return true;
	}

	chk[n] = true;  //방문 체크

	for (int i = 0; i < arr[n].size(); i++) { //다음 노드로 이동
		if (chk[arr[n][i]] == true) continue; //방문 했으면 다음노드 보기
		if (dfs(depth + 1, arr[n][i]) == true) {
			return true;
		}
	}

	chk[n] = false;

	return false;
}

int main(void) {
	int depth, N, M, a, b;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {  // 시작위치를 0 ~ N-1 까지 모든 경우를 다해봄.
		if (dfs(1, i) == true) {
			printf("1");
			return 0;
		}
	}
	printf("0");
}