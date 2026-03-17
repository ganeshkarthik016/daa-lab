#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter no.of elements : ";
    int n; cin>>n;
    int v[n];
    cout<<"Enter arr : ";
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
       cin>>v[i];
       maxi = max(maxi,v[i]);
    }
    int hash[maxi+1] = {0};
    int cnt = 0;
    for(int i=0;i<n;i++){
       if(hash[v[i]]==0) {hash[v[i]]++; cnt++;}
       else hash[v[i]]++;
    }
    int ans[cnt];
    int j =0;
    for(int i=0;i<n;i++){
        if(hash[v[i]]==1) {
            ans[j] = v[i];
            j++;
        }
                hash[v[i]]--;
    }
    for(int i = 0;i<cnt;i++){
        cout<<ans[i]<<" ";
    }

}