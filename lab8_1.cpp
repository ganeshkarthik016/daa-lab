
#include<bits/stdc++.h>
using namespace std;

int slove(int i, vector<int> &v, int tar, vector<vector<int>> &dp){
    int n = v.size();

    if(tar == 0) return 1;
    if(tar < 0) return 0;

    if(dp[i][tar] != -1) return dp[i][tar];

    int take = slove(0, v, tar - v[i], dp);  // reset i → allows all choices again
    int not_take = 0;

    if(i + 1 < n)
        not_take = slove(i + 1, v, tar, dp);

    return dp[i][tar] = take + not_take;
}

int main() {
    vector<int> a = {1,2,3,4,5,6}; 
    int tar; cin >> tar;

    vector<vector<int>> dp(6, vector<int>(tar+1, -1));

    int ans = slove(0, a, tar, dp);
    cout << ans << endl;
}