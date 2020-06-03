#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> m;
int n;
string fin;
vector<string> v;
int answer = 987987987;

void DFS(int x, string s){
    if(s.compare(fin) == 0){
        if(answer>x)answer = x;
        return;
    }
    if(x == n) return;
    else{
        for(int i=0; i<v.size(); i++){
            if(m[v[i]]>1) continue;
            int num = 0;
            for(int j=0; j<v[i].size(); j++){
                if(v[i][j] == s[j])num++;
            }
            if(num == s.size()-1){
                m[v[i]]++;
                DFS(x+1,v[i]);
                m[v[i]]--;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    n = words.size();
    v = words;
    fin = target;
    
    for(int i=0; i<words.size(); i++){
        m[words[i]]++;
    }
    
    DFS(0,begin);
    return answer == 987987987 ? 0 : answer;
}