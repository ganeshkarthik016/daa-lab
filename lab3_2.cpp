#include<bits/stdc++.h>
#define int long long
using namespace std;
int febi(int n){
    if(n==0||n==1) return 1;
    return febi(n-1) + febi(n-2);
}
int32_t main(){
    cout<<"Enter n: ";
    int n;cin>>n;
    clock_t now2 = clock();
    cout<<"Non recursive: "<<endl;
    cout<<"fibonacci :";
    vector<int> dp(n+1);
     dp[0] = 1;
     dp[1] = 1;
    for(int i=2;i<=n;i++){
       dp[i] = dp[i-1] + dp[i-2];
    }
    clock_t now3 = clock();
     double d = (double)(now3-now2) / CLOCKS_PER_SEC;
    for(int i = 0;i<=n;i++) cout<<dp[i] << " ";
    cout<<endl;
     cout<<"Time taken: "<<d<<endl;
    clock_t now = clock();
    cout<<"Recursive: "<<endl; 
    cout<<"fibonacci :";
    for(int i = 0;i<n;i++) cout<<febi(i)<<" ";
    cout<<endl;
    clock_t now1 = clock();
 double c = (double)(now1-now) / CLOCKS_PER_SEC;
 cout<<"Time taken: "<<c<<endl;
}