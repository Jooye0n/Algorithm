#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct person {
    int score;
    int name[26] = {0, };
};
int n;
string samsung = "SAMSUNG";
vector<person> v;//면접관 벡터
bool chk[10];
int result;
 
void DFS(int x, int score) {
    if (x == samsung.size()) {
        result = min(result, score);
        return;
    }
    else {
        int idx = samsung[x] - 'A';
        for (int i = 0; i < v.size(); i++) {
            if (v[i].name[idx] > 0) {
 
                v[i].name[idx]--;
 
                if (chk[i] == false) {
                    chk[i] = true;
                    DFS(x + 1, score + v[i].score);
                    chk[i] = false;
                }
                else DFS(x + 1, score);
 
                v[i].name[idx]++;
 
            }
        }
    }
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        v.clear();
        result = MAX;
        memset(chk, false, sizeof(chk));
 
        cin >> n;
        while (n--) {
            int L; cin >> L;//이름 길이
            person p;
            for (int i = 0; i < L; i++) {
                char S; cin >> S;
                p.name[S - 'A']++;
            }
            cin >> p.score;
            v.push_back(p);
        }
         
        DFS(0, 0);
        result = (result == MAX) ? -1 : result;
        printf("#%d %d\n", t, result);
    }
    return 0;
}