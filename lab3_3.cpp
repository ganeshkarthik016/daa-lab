#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;    
    int right = mid + 1;  
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high) {
    if (low == high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  
    mergeSort(arr, mid + 1, high); 
    merge(arr, low, mid, high); 
}
void mergere(int arr[], int low, int mid, int high)
{
   int temp[100];int  i=low, j=mid+1, k=0;

    while(i<=mid && j<=high)
        temp[k++] = (arr[i]<arr[j]) ? arr[i++] : arr[j++];

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=high) temp[k++] = arr[j++];

    for(i=low, k=0; i<=high; i++, k++)
        arr[i] = temp[k];
}
int main(){
    cout<<"Enter n: ";
    int n; cin>>n;
    cout<<"Enter array: ";
    int arr[n];   for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> v1 ;
    for(int i=0;i<n;i++) v1.push_back(arr[i]);
     clock_t now2 = clock();
    cout<<"Non recursive: "<<endl;
  for(int size=1; size<n; size*=2)
    {
        for(int low=0; low<n-1; low+=2*size)
        {
            int mid = low + size - 1;
            int high = min(low + 2*size - 1, n-1);
            mergere(arr, low, mid, high);
        }
    }
clock_t now3 = clock();
     double d = (double)(now3-now2) / CLOCKS_PER_SEC;
     cout<<"Sorted: "<<endl;
    for(int i = 0;i<n;i++) cout<<arr[i] << " ";
    cout<<endl;
     cout<<"Time taken: "<<d<<endl;
    clock_t now = clock();
    cout<<"Recursive: "<<endl; 
    mergeSort(v1,0,n-1);
    clock_t now1 = clock();
    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<v1[i]<<" ";
    cout<<endl;
 double c = (double)(now1-now) / CLOCKS_PER_SEC;
 cout<<"Time taken: "<<c<<endl;

}