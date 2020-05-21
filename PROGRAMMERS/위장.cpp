#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> m;
map<string,int> ::iterator iter;
vector<int> v;
int num,result=1;

int solution(vector<vector<string>> clothes) {

    for(int i=0; i<clothes.size(); i++) m[clothes[i][1]]++;
    for(iter = m.begin(); iter != m.end(); iter++){
        v.push_back(iter->second);
    }
    for(int i=0; i<v.size(); i++){
        result *= (v[i]+1);
    }
    
    return result-1;
}