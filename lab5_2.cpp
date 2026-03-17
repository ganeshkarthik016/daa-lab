#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> freq(n+1, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x >= n)
            freq[n-1]++;
        else
            freq[x]++;
    }
    int last = 0;
    for(int i = n; i >= 0; i--){
        last += freq[i];
        if(last == i){
            cout << i<<endl;
            break;
        }
    }
}


