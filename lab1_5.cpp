#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    stack<int> st; queue<char> qu;
    for(char c: s){
        qu.push(c);    }
        while(!qu.empty()){
            int a,b;
            if(qu.front() == '+'){
                a = st.top() ; st.pop(); b = st.top();st.pop();
                int c = b + a;
                st.push(c);
                qu.pop();
            }
            else if( qu.front() == '-'){
                a = st.top() ; st.pop(); b = st.top();st.pop();
                int c = b - a;
                st.push(c);
                qu.pop();
            }
            else if( qu.front() == '*'){
                a = st.top() ; st.pop(); b = st.top();st.pop();
                int c = b * a;
                st.push(c);
                qu.pop();
            }
            else if(qu.front() == '/'){
                a = st.top() ; st.pop(); b = st.top();st.pop();
                int c = b / a;
                st.push(c);
                qu.pop();
            }
            else{

                st.push(qu.front() - '0');
                qu.pop();
            }
        }
        int ans = st.top();
        st.pop();
        cout<<ans<<endl;

} 
