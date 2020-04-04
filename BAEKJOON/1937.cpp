#include <iostream>
using namespace std;
 
int dp[500][500];
int map[500][500];

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int n;
int ans;

int dfs(int y,int x){
    //이 위치에서 가장 멀리 갈 수 있는 거리
    if(dp[y][x]>0) return dp[y][x];
    else{
        dp[y][x]=1;
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(nx>=0 && nx<n && ny>=0 && ny<n && map[y][x]<map[ny][nx])
                dp[y][x]=max(dp[y][x],dfs(ny,nx)+1);
        }
        return dp[y][x];
    }
}
int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}