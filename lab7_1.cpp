#include<bits/stdc++.h>
using namespace std;
int slove(int i,vector<int> &v,int tar,vector<vector<int>> &dp){
 int n = v.size();
 if(tar == 0) return 1;
 if(tar<0 || i==n) return 0;
 if(dp[i][tar] != -1) return dp[i][tar];
 int take = slove(i,v,tar - v[i],dp);
 int not_take = slove(i+1,v,tar,dp);
 return dp[i][tar] = take+not_take;
}
int main() {
  int n;cin>>n;
  vector<int> a(n); for(int i=0;i<n;i++)  cin>>a[i];
  int tar;cin>>tar;
  vector<vector<int>> dp = vector<vector<int>> (n,vector<int> (tar+1,-1));
   int ans = slove(0,a,tar,dp);
   cout<<ans<<endl;
}