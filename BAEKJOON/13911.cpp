#include <bits/stdc++.h>
#define LIMIT 987987987
#define MAX 10003
#define STAR 10001 //더미 노드
#define MAC 10002
using namespace std; 
int n, m;
int mac, star;
int macD, starD;

vector<pair<int, int> > v[MAX]; //연결관계 저장
int minDist[MAX][2]; //(0)스-집 의 최단거리 저장 //(1)맥-집 의 최단거리 저장

void foundShortCut(int x, int idx) {
	//x번 더미 노드와 집까지의 최단 거리 전부 구하기
	queue<int> q; //노드 번호, 거리

	for (int i = 0; i < v[x].size(); i++) {
		q.push(v[x][i].first); 
		minDist[v[x][i].first][idx] = 0;
	}

	while (q.empty() == false) {
		int cx = q.front(); q.pop();
		int cdist = minDist[cx][idx];

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i].first;
			int ndist = v[cx][i].second;
			
			if (minDist[nx][idx] > cdist + ndist) {
				minDist[nx][idx] = cdist + ndist;
				q.push(nx);
			}
		}
	}
}

int getTotalMin() {
	//조건을 만족하는 최소 거리를 return
	//조건을 만족하는 경우가 없다면 -1 return

	int result = LIMIT;

	for (int i = 1; i <= n; i++) {
		if ( minDist[i][0] != 0 && minDist[i][1] != 0 && minDist[i][0] <= starD && minDist[i][1] <= macD) {
			result = min(result, minDist[i][0] + minDist[i][1]);
		}
	}

	return result == LIMIT ? -1 : result;
}

void init() {
	//초기화
	for (int i = 1; i <= n; i++) {
		minDist[i][0] = LIMIT; //스타벅스
		minDist[i][1] = LIMIT; //맥도날드
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}

	init();

	cin >> mac >> macD;
	for (int i = 0; i < mac; i++) {
		int num; cin >> num;
		v[MAC].push_back(make_pair(num, 0));
	}

	cin >> star >> starD;
	for (int i = 0; i < star; i++) {
		int num; cin >> num;
		v[STAR].push_back(make_pair(num, 0));
	}

	foundShortCut(STAR, 0);
	foundShortCut(MAC, 1);
	cout<<getTotalMin();
	return 0;
}