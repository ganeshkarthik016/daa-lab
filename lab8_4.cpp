#include<bits/stdc++.h>
using namespace std;
int bfs(int i,vector<pair<int,pair<int,int>>> &p,int cnt,int last,vector<vector<int>> &dp){
    int n = p.size();
    if(i==n) return cnt;
    if(dp[i][last]!=-1) return dp[i][last];
    if(p[i].second.second <= last) return bfs(i+1,p,cnt,last,dp);
    int take = bfs(i+1,p,cnt + 1,p[i].first,dp);
    int not_take =  bfs(i+1,p,cnt,last,dp);
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
        vector<vector<int>> dp(n,vector<int> (p[n-1].first,-1));
    cout<<bfs(0,p,0,0,dp);
}