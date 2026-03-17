
#include<bits/stdc++.h>
#include<random>
using namespace std;
void swap(int *a,int *b){
    int temp = *a; *a = *b; *b = temp;
}
int pari(int arr[], int low, int high) {
    int p = arr[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(arr[i] <= p && i <= high - 1) i++;
        while(arr[j] > p && j >= low + 1) j--;
        if(i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void sort(int arr[], int low, int high) {
    if(low < high) {
        int p = pari(arr, low, high);
        sort(arr, low, p - 1);
        sort(arr, p + 1, high);
    }
}
int main(){
    cout<<"Enter no.of arrays : ";
    int t ; cin>>t;
    int original_t = t;
    int p = 1;
    double time_taken[original_t];
while(t--){
    clock_t now = clock();
 int n = p ;
 int v[n];
    for(int i = 0;i<n;i++){
       v[i] = rand()%100 + 1;
    }
    cout<<"Your  random array is : ";
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
  cout<<endl;
  cout<<"Sorted : ";
   sort(v,0,n-1);
 for(int i=0;i<n;i++) cout<<v[i]<<" ";
 cout<<"\n";
 clock_t now1 = clock();
 double c = (double)(now1-now) / CLOCKS_PER_SEC;
 time_taken[p-1] = c;
  p++;
}
cout << "Table of time taken:\n";
cout << "Array No.\tTime (sec)\n";
for(int i = 0;i<original_t;i++){
    cout << i+1 << "\t\t" << time_taken[i] << endl;
}
}
