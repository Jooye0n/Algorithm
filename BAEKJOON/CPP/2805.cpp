/*
나무자르기
*/

#include <stdio.h>

using namespace std;
int k;
int arr[10000001];
int maxNum;
int n;


int cut(int x){
    //x만큼 잘랐을 경우 얻는 나무가 k보다 크면 1 작으면 -1 k면 0 return
    long long total = 0;

    for(int i=0; i<n; i++){
        if(arr[i]>x)
            total +=arr[i]-x;
    } 

    if(total>k){
        return 1;
    }else if(total<k){
        return -1;
    }else{
        return 0;
    }
}

int main() {

  //Please Enter Your Code Here
  
  scanf("%d",&n);
  scanf("%d",&k);

  for(int i=0; i<n; i++){
      scanf("%d", &arr[i]);
      if(arr[i]>=maxNum){
          maxNum= arr[i];
      }
  }

  //나무 높이 - 절단 높이 들의 합 = 집에 가져가는 나무

  int start = 0;
  int end = maxNum;
  int mid;

  while(start+1<end){
      mid = (start+end) / 2;
      int r = cut(mid);

      if(r == 1){
          start = mid;
      }else if(r == -1){
          end = mid;
      }else if(r == 0){
          printf("%d\n",mid);
          return 0;
      }
  }

  printf("%d\n",start);

  return 0;
}