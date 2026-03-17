
#include <bits/stdc++.h>
using namespace std;

void merge(int  arr[], int low, int mid, int high) {
    int temp[high - low];
    int left = low;     
    int right = mid + 1;  
    int i = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[i] = arr[left];
i++;
            left++;
        }
        else {
           temp[i] = arr[right];
i++;
            right++;
        }
    }

    while (left <= mid) {
        temp[i] = arr[left];
i++;
        left++;
    }
    while (right <= high) {
       temp[i] = arr[right];
i++;
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int  arr[], int low, int high) {
    if (low == high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  
    mergeSort(arr, mid + 1, high); 
    merge(arr, low, mid, high); 
}

int main() {

    cout<<"Enter no.of elements n and m: ";

    int n; cin>>n; int m; cin>>m;
    cout<<"Enter k: "; int k; cin>>k;
    int v[n],a[m];
    cout<<"Enter arr 1: ";
     for(int i = 0;i<n;i++){
       cin>>v[i];
    }
    cout<<"Enter arr 2: ";
     for(int i = 0;i<m;i++){
       cin>>a[i];
    }
    int temp[n+m];
    for(int i=0;i<n+m;i++){
        if(i<n)temp[i] = v[i];
        else temp[i] = a[i-n];
    }
    mergeSort(temp , 0,m+n-1);
    cout<<temp[k-1]<<endl;

}

