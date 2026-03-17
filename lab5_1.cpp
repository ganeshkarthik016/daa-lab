#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m; cin>>n>>m;
    vector<int> arr1;
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
       int p; cin>>p;
       arr1.push_back(p);
       freq[p]++;
    }
    vector<int> arr2(m),ans;
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    for(int i=0;i<m;i++){
        int c = freq[arr2[i]];
        for(int j=0;j<c;j++){
            ans.push_back(arr2[i]);
            freq[arr2[i]]--;
        }
    }
    vector<int> semi;
    for(auto [k,a] : freq){
        if(a!=0){
            for(int i=0;i<a;i++){
                semi.push_back(k);
            }
        }
    }
   sort(semi.begin(),semi.end());
   int x = semi.size();
   for(int i=0;i<x;i++){
    ans.push_back(semi[i]);
   }
    cout<<"Ans: ";
    for(int i=0;i<ans.size();i++){
     cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}