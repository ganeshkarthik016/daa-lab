#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int temp[100], i=low, j=mid+1, k=0;

    while(i<=mid && j<=high)
        temp[k++] = (arr[i]<arr[j]) ? arr[i++] : arr[j++];

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=high) temp[k++] = arr[j++];

    for(i=low, k=0; i<=high; i++, k++)
        arr[i] = temp[k];
}

int main()
{
      int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for(int size=1; size<n; size*=2)
    {
        for(int low=0; low<n-1; low+=2*size)
        {
            int mid = low + size - 1;
            int high = min(low + 2*size - 1, n-1);
            merge(arr, low, mid, high);
        }
    }

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}