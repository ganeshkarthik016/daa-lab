#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<int> seen(n,0);
    int src = 0;
    seen[src] = 1;
    int ans = 0;
    int cnt = 0;
    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;
    for(int i=0;i<n;i++){
        if(a[src][i]!=-1 && a[src][i]!=0)
            pq.push({a[src][i],{src,i}});
    }

    while(!pq.empty() && cnt < n-1){
        auto [cost, edge] = pq.top();
        pq.pop();
        int u = edge.first;
        int v = edge.second;
        if(seen[v]) continue;
        seen[v] = 1;
        ans += cost;
        cnt++;
        for(int w=0; w<n; w++){
            if(!seen[w] && a[v][w]!=-1 && a[v][w]!=0){
                pq.push({a[v][w],{v,w}});
            }
        }
    }

    if(cnt != n-1) cout<<-1;
    else cout<<ans;
}