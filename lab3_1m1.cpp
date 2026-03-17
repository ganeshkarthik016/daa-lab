#include<bits/stdc++.h>
#include<random>
using namespace std;
int  search(vector<int> v,int target,int n,int i){
  if(n==i)  return -1;
  if(v[i]==target) return i;
  return search(v,target,n,++i);
}
int main(){
    int n;n = rand()%100 + 1;
    cout<<"Array: ";
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i]= rand()%100 + 1;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Target: ";
    int target;
    cin>>target;
    clock_t now = clock();
    cout<<"Recursive: "<<endl; 
    int ans = search(a,target,n,0);
    clock_t now1 = clock();
 double c = (double)(now1-now) / CLOCKS_PER_SEC;
    if(ans != -1) cout<<"ans: " << ans+1 << "th element\n ";
    else cout<<"Not found\n";
    cout<<"Time taken: "<<c<<endl;
    clock_t now2 = clock();
    cout<<"Non recursive: "<<endl;
    int ans1 = -1;
    for(int i = 0;i<n;i++){
        if(a[i]==target){
            ans1 = i;
            break;
        }
    }
    clock_t now3 = clock();
     double d = (double)(now3-now2) / CLOCKS_PER_SEC;
if(ans1 != -1) cout<<"ans: " << ans+1 << "th element\n ";
    else cout<<"Not found\n";
 cout<<"Time taken: "<<d<<endl;
}