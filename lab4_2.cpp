#include <bits/stdc++.h>
using namespace std;
void algo(vector<int> v,int n){
  if(n<1) return;
  cout<<v[n]<<endl;
  algo(v,n/2);
}
int main(){
   
    int n;cin>>n;
    vector<int> v(n);
    for(int  i=0;i<n;i++){
        cin>>v[i];
    }
     cout<<" T(N) = 1 + T(N/2) :"<<endl;
    algo(v,n-1);
   cout<<" T(N) = O(n) :"<<endl;
  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
  cout<<" T(N) = O(n^3) :"<<endl;
  for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            cout<<v[i]<<" ";
        }
    }
  }
  cout<<endl;
}