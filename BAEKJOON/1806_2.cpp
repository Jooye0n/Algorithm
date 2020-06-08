#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
vector<int> map;

int n, m;

int main(void) {
   int resLen=1000000;
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      map.push_back(temp);
   }
   map.push_back(0); map.push_back(0);
   int small = 0; int big = 0;

   long long int sum = map[big];
   while (small<=big&&small < n && big < n) {//하나라도 넘어가면 끝난다 
      if (sum < m) {
         big++;
         sum+=map[big];
   //      cout << "big증가" << endl;
      }
      else if (sum == m) {
         if (resLen > big - small + 1) {
            resLen = big - small + 1;
         }
         big++;
         sum += map[big];
      }
      else if (sum > m) {
         if (resLen > big-small+1 ) {
            resLen = big - small + 1;
         }
         //cout << "small증가" << endl;

         sum -= map[small];
         small++;
      }
   //   cout << big << small << endl;
      
   }//종료조건
   cout << resLen;
}