#include<bits/stdc++.h>
using namespace std; 
struct node{
  char c;
  struct node* lnext;
  struct node* rnext;
};
void generate(node* root, string s, unordered_map<char, string> &mp) {
    if(!root) return;

    if(!root->lnext && !root->rnext) {
        mp[root->c] = s;
    }

    generate(root->lnext, s + "0", mp);
    generate(root->rnext, s + "1", mp);
}
int main(){
    int n; cin>>n;
    priority_queue<pair<int ,struct node*>,vector<pair<int ,struct node*>>,greater<pair<int ,struct node*>>> cp;
    for(int i=0;i<n;i++){
        char p; cin>>p;
        int fr; cin>>fr;
        struct node* s = new struct node;
        s->c = p;
         s->rnext = nullptr;
        s->lnext = nullptr;
        cp.push({fr,s});
    }
    while(cp.size()>1){

        node* right = cp.top().second;int rf = cp.top().first;  cp.pop();
        node* left = cp.top().second;int lf = cp.top().first; cp.pop();
        node* root = new node;
        root->c = '#';
        root->rnext = right;
        root->lnext = left;
        cp.push({rf+lf,root});
       
      
    }
    node* root = cp.top().second;

    unordered_map<char,string> mp;

    generate(root, "", mp);
    for(auto it : mp) {
        cout << it.first << " : " << it.second << "\n";
    }
}