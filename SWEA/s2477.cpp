#include <bits/stdc++.h>
using namespace std;
struct person {
    int A, B;
};
 
struct store {
    int cnt;//들어갈때의 시간
    int timer;//처리 시간
    int num;
};
 
int n, m, k, A, B;
store Astore[10];
store Bstore[10];
person answer[1001];//정답 저장
vector<pair<int, int> > Ptime;//사람 도착 시간, 번호 저장
int curTime;//현재 시간
int emptyA;//비어있는 A 개수
int emptyB;//비어있는 B 개수
int finPerson;//나온 사람 수
 
void gotoB(int x) {
    for (int i = 1; i <= m; i++) {
        if (Bstore[i].num == 0) {
            answer[x].B = i;
            Bstore[i].num = x;
            Bstore[i].cnt = curTime;
            return;
        }
    }
}
 
void gotoA(int x) {
    for (int i = 1; i <= n; i++) {
        if (Astore[i].num == 0) {
            answer[x].A = i;
            Astore[i].num = x;
            Astore[i].cnt = curTime;
            return;
        }
    }
}
 
bool cmp(const pair<int, int> &p1,const pair<int, int> &p2) {
    //first는 작은순으로
    //first같은 경우 sec작은순으로
    if (p1.first < p2.first) return true;
    else if (p1.first == p2.first) {
        return (p1.second < p2.second);
    }
    else return false;
}
 
void Simul() {
    //시간순으로 정렬
    queue<pair<int, int> > q;
    queue<int> watingB;
    queue<int> watingA;
 
    sort(Ptime.begin(), Ptime.end(),cmp);
    for (int i = 0; i < Ptime.size(); i++) {
        q.push(Ptime[i]);
    }
 
    while (true) {
        //B창구 -> 끝
        for (int i = 1; i <= m; i++) {
            if (emptyB == m) break;
            if (Bstore[i].num == 0) continue;
 
            if (curTime - Bstore[i].cnt == Bstore[i].timer) {
                Bstore[i].cnt = 0;
                Bstore[i].num = 0;
                emptyB++;
                finPerson++;
            }
        }
 
        //A창구 -> 대기B
        for (int i = 1; i <= n; i++) {
            if (emptyA == n) break;
            if (Astore[i].num == 0) continue;
 
            if (curTime - Astore[i].cnt == Astore[i].timer) {
                watingB.push(Astore[i].num);
 
                Astore[i].cnt = 0;
                Astore[i].num = 0;
 
                emptyA++;
            }
        }
 
        //대기B -> B창구
        while (watingB.empty() == false) {
            if (emptyB == 0) break;
            gotoB(watingB.front());
            watingB.pop();
            emptyB--;
        }
 
        //대기Q -> 대기A
        while (q.empty() == false && q.front().first == curTime) {
            watingA.push(q.front().second);
            q.pop();
        }
 
        //대기A -> A창구
        while (watingA.empty() == false) {
            if (emptyA == 0) break;
            gotoA(watingA.front());
            watingA.pop();
            emptyA--;
        }
 
        if (finPerson == k) break;
        else curTime++;
    }
}
 
int getResult() {
    int result = 0;
    for (int i = 1; i <= k; i++) {
        if (answer[i].A == A && answer[i].B == B) result += i;
    }
    return result == 0 ? -1 : result;
}
 
void init() {
    curTime = 0;
    emptyA = n;
    emptyB = m;
    Ptime.clear();
    finPerson = 0;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> m >> k >> A >> B;
        init();
        for (int i = 1; i <= n; i++) {
            cin >> Astore[i].timer;
        }
        for (int i = 1; i <= m; i++) {
            cin >> Bstore[i].timer;
        }
 
        for (int i = 1; i <= k; i++) {
            int temp;  cin >> temp;
            Ptime.push_back(make_pair(temp, i));
        }
 
        Simul();
        printf("#%d %d\n", t, getResult());
    }
    return 0;
}