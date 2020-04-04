// /*
// [ 순열의 순서 ]
// https://www.acmicpc.net/problem/1722
// http://blog.naver.com/PostView.nhn?blogId=591923&logNo=220911515586

// 문제
// 1부터 N까지의 수를 임의로 배열한 순열은 총 N! = N×(N-1)×…×2×1 가지가 있다.

// 임의의 순열은 정렬을 할 수 있다. 예를 들어  N=3인 경우 {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}의 순서로 생각할 수 있다. 첫 번째 수가 작은 것이 순서상에서 앞서며, 첫 번째 수가 같으면 두 번째 수가 작은 것이, 두 번째 수도 같으면 세 번째 수가 작은 것이….

// N이 주어지면, 아래의 두 소문제 중에 하나를 풀어야 한다. k가 주어지면 k번째 순열을 구하고, 임의의 순열이 주어지면 이 순열이 몇 번째 순열인지를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N(1≤N≤20)이 주어진다. 둘째 줄의 첫 번째 수는 소문제 번호이다. 1인 경우 k(1≤k≤N!)를 입력받고, 2인 경우 임의의 순열을 나타내는 N개의 수를 입력받는다. N개의 수에는 1부터 N까지의 정수가 한 번씩만 나타난다.

// 출력
// k번째 수열을 나타내는 N개의 수를 출력하거나, 몇 번째 수열인지를 출력하면 된다.

// 예제 입력 1 
// 4
// 1 3
// 예제 출력 1 
// 1 3 2 4


// 예제 입력 2 
// 4
// 2 1 3 2 4
// 예제 출력 2 
// 3
// */

// #include <cstdio>
// #include <iostream>

// using namespace std;
// int n,m;
// long long k;
// int arr[21];
// long long fac[21];
// bool chk[21];

// void makeFac(int x){
//     for(int i=3; i<x; i++){
//         fac[i] = fac[i-1]*i;
//     }
// }

// void found1(int x) {
//     if(x == 1){
//         for(int i = 1; i <= n; i++){
//             if(chk[i] == false){
//                 cout<<i<<'\n';
//                 return;
//             }
//         }
//     }else{
//         for(int i = 1; i <= n; i++){
//             if(chk[i] == true) continue;
//             if(k <= fac[x - 1]){
//                 cout<<i<<' ';
//                 chk[i] = true;
//                 found1(x - 1);
//                 return;
//             }
//             k -= fac[x - 1];
//         }
//     }
// }
// //1 3 2 4
// int found2(int x, int N){
//     long long result = 0;
 
//     if (x == n - 2){
//         return 1;
//     }
 
//     for (int i = 1; i <= n; i++)
//     {
//         if (chk[i]) continue;
//         if (i == arr[x])
//         {
//             chk[i] = 1;
//             return found2(x + 1, N - 1) + result;
//         }
 
//         result += fac[N - 1];
//     }
// }

// int main(){
//     cin>>n;
//     cin>>m;

//     fac[1] = 1;
//     fac[2] = 2;

//     makeFac(n);

//     if(m == 1){
//         cin>>k;
//         found1(n);
//     }else if(m == 2){
//         for(int i=0; i<n; i++){
//             cin>>arr[i];
//         }
//         cout<<found2(0,n);
//     }
//     return 0;
// }

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
long long factorial[21];
vector<int> arr;
vector<bool> chk;
int n, p;
long long result = 1;

void found1(int x, long long int k) {
    if (x == 1){
        for (int i = 1; i <= chk.size(); i++){
            if (chk[i] == false){
                cout<<i;
                return;
            }
        }
    }
    else{
        for (int i = 1; i <= chk.size(); i++){
            if (chk[i] == false){
                if (k <= factorial[x - 1]){
                    cout<<i<<' ';
                    chk[i] = 1;
                    found1(x - 1, k);
                    return;
                }
                k -= factorial[x - 1];
            }
        }
    }
}
 
void found2(long long x, int k) {
    if (x == n-1){
        cout<<result;
    }else{
        for(int i = 1; i <= n; i++){
            if (chk[i] == false){
                if (i == arr[x]){
                    chk[i] = true;
                    found2(x + 1, k - 1);
                }
                result += factorial[k - 1];
            }
        }
    }
}
 
int main()
{
    long long k;
 
    cin >> n >> p;
    chk.resize(n+1);

    /* 팩토리얼 만들기 */
    factorial[0] = 1;
    for (int i = 1; i <= 20; i++){
        factorial[i] = factorial[i - 1] * i;                                                                                         
    } 

    /* 소문제 */
    if(p == 1){
        cin >> k;
        found1(n, k);
    }
    else if(p == 2){
        for(int i = 0; i < n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        found2(0, n);
    }

    return 0;
}