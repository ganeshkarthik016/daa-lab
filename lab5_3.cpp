#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin>>s;
  vector<int> freq(26,0);
for(char c : s){
    freq[c - 'a']++;
}
vector<pair<int,char>> arr;
for(int i = 25; i >= 0; i--){
    if(freq[i] > 0)
        for(int j = 0;j<freq[i];j++) arr.push_back({freq[i], char('a' + i)});
}
sort(arr.begin(), arr.end(), greater<>());
string ans = "";
for(auto p : arr){
    ans += p.second;
}
cout << ans << endl;
}