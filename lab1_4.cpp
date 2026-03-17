#include <bits/stdc++.h>
using namespace std;

void solve(){
    int t; t = 1;
    while(t--){
        string s; cin>>s;
        queue<char> qu;
        stack<char> st;
        for(char c : s){
          qu.push(c);
        }
       while(!(qu.empty())){
           if(!(st.empty())&&(st.top() ==qu.front())){
              st.pop();
              qu.pop();;
           }
           else{
            st.push(qu.front());
            qu.pop();
           }
        }
        stack<char> an;
        queue<char> ans;
        while(!(st.empty())){
            ans.push(st.top());
            st.pop();
        }
        while(!(ans.empty())){
            an.push(ans.front());
            ans.pop();
        }
        if(!(an.empty())) cout<<an.top()<<endl;
        else cout<<-1<<endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}