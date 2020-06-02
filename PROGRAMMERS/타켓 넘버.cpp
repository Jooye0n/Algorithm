#include <string>
#include <vector>

using namespace std;
vector<int> v;
int tag;
int result;
void DFS(int x, int total){
    if(x == v.size()){
        if(total == tag) result++;
    }else{
        DFS(x+1,total-v[x]);
        DFS(x+1,total+v[x]);
    }
}
int solution(vector<int> numbers, int target) {
    v = numbers;
    tag = target;
    DFS(0,0);
    return result;
}