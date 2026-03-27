#include<bits/stdc++.h>
using namespace std;
int dfs(int i,vector<pair<int,pair<int,int>>> &p,int amount,int last,vector<vector<int>> &dp){
    int n = p.size();
    if(i==n) return amount;
    if(dp[i][last]!=-1) return dp[i][last];
    if(p[i].second.second <= last) return dfs(i+1,p,amount,last,dp);
    int take = dfs(i+1,p,amount + p[i].second.first,p[i].first,dp);
    int not_take =  dfs(i+1,p,amount,last,dp);
    return dp[i][last] =  max(take,not_take);
}
int main(){
    int n;cin>>n;
    vector<pair<int,pair<int,int>>> p;
    for(int i=0;i<n;i++) {
        int a,b,c; cin>>a>>b>>c;
        p.push_back({b,{c,a}});
    }
    sort(p.begin(),p.end());
        vector<vector<int>> dp(n,vector<int> (p[n-1].first+1,-1));
    cout<<dfs(0,p,0,0,dp);
}