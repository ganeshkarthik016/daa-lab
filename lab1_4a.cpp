#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    vector<int> v(26,0);
    for(char c : s){
        v[c-97]++;
    }
    for(int i = 0 ;i<26;i++){
        if(v[i] == 1){
            char c = 'a' + i;
            cout<<c<<endl;
            break;
        }
    }
}
