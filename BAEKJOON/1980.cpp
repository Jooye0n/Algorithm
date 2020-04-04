/*
[ 라비다 1980 ]
비밀번호 자리수 N과 비밀번호 각 자리의 최대값이 입력될 때,
가능한 모든 좌물쇠 비밀번호를 오름차순으로 하나씩 출력하기.

입력
1//테스트 케이스
3//비밀번호 자리수
1 2 2//각 자리 최대값

출력
0 0 0
0 0 1
0 0 2
0 1 0
0 1 1
...
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> arr(1);

void printNum(int pos, int n);

int main() {
    
    
    int num;
    cout<<"자리수입력";
    cin>>num;
    arr.resize(num);

    for(int i=0; i<num ; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    printNum(0, num);
    return 0;

}

//reculsive 함수 구현
void printNum(int pos, int n) {
for(int i=0; i<=v[pos];i++) {
    //각 자리수의 최대값까지 구현
    arr[pos] = i;
    if(pos == n-1) {
        for(int j=0; j<n-1;j++) {
            cout<<arr[j];
        }
        cout<<arr[n-1]<<'\n';
    }else { //아직 안끝났으면 다음 자리수로 넘어간다.
        printNum(pos+1,n);
    }
}
}


