/*
숨바꼭질
https://www.acmicpc.net/problem/13913

수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다
1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로

5 17

4
5 10 9 18 17

*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,k;
queue<int> q;
int result;
int chk[200001];
vector<int> v;

int main(){

    fill(&chk[0],&chk[200001],-1);

    cin>>n>>k;
    chk[n] = 0;
    q.push(n);

    while(q.empty() == false){
        
        int size = q.size();
        for(int i=0 ;i<size; i++){
            int current = q.front();q.pop();

            if(current == k){
                cout<<result;
                cout<<'\n';

                while(current != n){
                    v.push_back(current);
                    current = chk[current];
                }
                v.push_back(n);
                int size = v.size();
                for(int i=size-1; i>=0; i--){
                    cout<<v[i]<<' ';
                }
                return 0;
            }else{
                if(current-1>=0 && chk[current-1] == -1){
                    chk[current-1] = current;
                    q.push(current-1);
                }
                
                if(current+1<=200000 && chk[current+1] ==-1){
                    chk[current+1] = current;
                    q.push(current+1);
                }
                
                if(current*2<=200000 && chk[current*2] == -1){
                    chk[current*2] = current;
                    q.push(2*current);
                }
            }
        }
        result++;
    }




    return 0;
}

