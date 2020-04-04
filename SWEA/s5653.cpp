/*

2 2 10
1 1
0 2
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[352][352];


int main(){
    cin>>n>>m>>k;
    for(int i=150; i<150+n; i++){
        for(int j=150;j<150+m; j++){
            cin>>arr[i][j];
        }
    }

    
    return 0;
}