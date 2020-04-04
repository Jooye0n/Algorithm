#include <iostream>
#include <queue>
#include <vector>
#define MAX 101001

using namespace std;
 
int N, K, M;
vector<int> v[MAX];
 
int BFS(){
    queue<int> q;
    int chk[MAX] = {0, };
    chk[1] = 1;
    q.push(1);

    while(q.empty() == false){
        int cx = q.front(); q.pop();

        if(cx == N) return chk[cx];
        
        for(int i=0; i<v[cx].size(); i++){
            int nx = v[cx][i];
            if(chk[nx] == 0){
                chk[nx] = chk[cx];
                if(nx<=N) chk[nx]++;
                q.push(nx);
            }
        }
    }
    return -1;
}

int main(void){
    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++){
        for (int j = 0; j < K; j++){
            int a; cin >> a;
            v[a].push_back(i + N);//역에는 하이퍼 튜브들을 넣어준다.
            v[i + N].push_back(a);//하이퍼 튜브에는 역들을 넣어준다.
        }
    }

    int Answer = BFS();
    cout << Answer;
    return 0;
}