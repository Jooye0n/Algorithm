#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;
vector <int> op; // +,-,*,/
vector <int> operand;
int N; // 2<=N<=11
int maximum=-987987987;
int minimum=987987987;

int T;

void dfs(int index, int sum){
   if(index==N){
      if(maximum< sum){
         maximum=sum;
      }
      if(minimum>sum){
         minimum=sum;
      }
      return;
   }else{
       for(int i=0; i<op.size();i++){
            if(op[i]>=1){
                if(i==0){
                    op[i]-=1;
                    dfs(index+1,operand[index]+sum);
                    op[i]+=1;
                }
                else if(i==1){
                    op[i]-=1;
                    dfs(index+1,sum - operand[index]);
                    op[i]+=1;
                }
                else if(i==2){
                    op[i]-=1;
                    dfs(index+1,operand[index]*sum);
                    op[i]+=1;
                }
                else if(i==3){
                    op[i]-=1;
                    dfs(index+1,sum/operand[index]);
                    op[i]+=1;
                }
            }
        }
   }
}

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        maximum=-987987987;
        minimum=987987987;
        operand.clear();
        op.clear();
        
         cin >> N;
        for(int i=0; i<4;i++){
            int number;
            cin >> number;
            op.push_back(number);
        }

        for(int i=0; i<N;i++){
            int number;
            cin >> number;
            operand.push_back(number);
        }

        dfs(1,operand[0]);
        cout<<'#'<<t<<' '<<maximum-minimum<<'\n';
    }
   
    return 0;
}