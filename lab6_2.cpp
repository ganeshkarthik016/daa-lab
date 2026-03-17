#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int boxes[n][2];
    int size; cin>>size;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        cin>>boxes[i][0]>>boxes[i][1];
        pq.push({boxes[i][1],boxes[i][0]});
    }
    int ans  = 0;
    while(size>0&&!(pq.empty())){
      auto fe = pq.top();pq.pop();
      if(fe.second<=size){
        ans += fe.second*fe.first;
        size -= fe.second;
      }
      else{
        ans += size*fe.first;
        size = 0;
        break;
      }
    }
    cout<<ans<<endl;
}