#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void algo1(vector<int> &v, int low, int high){
    if(high - low + 1 == 2){
        if(v[low] > v[high])
            swap(v[low], v[high]);
        return;
    }

    if(high - low + 1 > 2){
        int n = high - low + 1;
        int m = ceil((2.0 * n) / 3);
        algo1(v, low, low + m - 1);
        algo1(v, high - m + 1, high);
        algo1(v, low, low + m - 1);
    }
}
void algo2(vector<int> &v, int low, int high){
    if(high - low + 1 == 2){
        if(v[low] > v[high])
            swap(v[low], v[high]);
        return;
    }

    if(high - low + 1 > 2){
        int n = high - low + 1;
        int m = (2.0 * n) / 3;
        algo2(v, low, low + m - 1);
        algo2(v, high - m + 1, high);
        algo2(v, low, low + m - 1);
    }
}
int main() {
   int n;cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   vector<int> temp1,temp2;
   temp1 =  v;
   temp2 = v;
   clock_t now = clock();
   algo1(temp1,0,n-1);
   for(int i=0;i<n;i++){
    cout<<temp1[i]<<" ";
   }
   clock_t now1 = clock();
 double c = (double)(now1-now) / CLOCKS_PER_SEC;
   cout<<endl;
   cout<<"Time taken algo1: "<<c<<endl;
   clock_t now2 = clock();
   algo2(temp2,0,n-1);
    for(int i=0;i<n;i++){
    cout<<temp2[i]<<" ";
   }
   cout<<endl;
   clock_t now3 = clock();
     double d = (double)(now3-now2) / CLOCKS_PER_SEC;
     cout<<"Time taken algo2: "<<d<<endl;
}