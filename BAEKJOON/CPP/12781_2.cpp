#include <bits/stdc++.h>
using namespace std;
int score[50][10];//이닝 별 선수들의 점수
int n;//이닝 0부터 시작
int person[10]; //이닝별 정해진 선수 순서
bool chk[10];
int result;

int playGame() {
	//0 ~ n-1이닝 경기 후 결과 return
	int cnt = 0; //현재 이닝 카운트
	int total = 0; //점수
	bool ground[4] = { false, };
	int curIdx = 1;//현재 타자 인덱스
	int cntOut = 0;//아웃 카운트

	while (cnt<n) {
		//공을 치고 움직인다.
		int p = person[curIdx];
		int num = score[cnt][p];
		switch (num)
		{
		case 1:
			if (ground[3] == true) total++;
		
			ground[3] = ground[2];
			ground[2] = ground[1];
			ground[1] = true;

			break;
		case 2:
			if (ground[3] == true) total++;
			if (ground[2] == true) total++;

			ground[3] = ground[1];
			ground[2] = true;
			ground[1] = false;

			break;
		case 3:
			if (ground[3] == true) total++;
			if (ground[2] == true) total++;
			if (ground[1] == true) total++;

			ground[3] = true;
			ground[2] = false;
			ground[1] = false;
			break;
		case 4:
			if (ground[3] == true) total++;
			if (ground[2] == true) total++;
			if (ground[1] == true) total++;

			total++;
			ground[3] = false;
			ground[2] = false;
			ground[1] = false;
			break;
		case 0:
			cntOut++;
			break;
		}

		curIdx = curIdx % 9 + 1;

		if (cntOut == 3) 
		{
			cntOut = 0;
			memset(ground, false, sizeof(ground));
			cnt++;
		}
	}

	return total;
}

void choice(int x) {
	//선수 순서 정하기
	if (x == 10) {
		result = max(result,playGame());
	}
	else if (x == 4) {
		choice(x + 1);
	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (chk[i] == false) {
				chk[i] = true;
				person[x] = i;
				choice(x + 1);
				chk[i] = false;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> score[i][j];
		}
	}
	person[4] = 1;
	chk[1] = true;
	choice(1);
	cout << result;
	return 0;
}