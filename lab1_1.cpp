#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fr(i,a,b) for(int i = a; i < b; i++)
#define add(v) accumulate((v).begin(), (v).end(), 0LL)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
#define in(v,n) vi v(n); fr(i,0,n) cin>>v[i];

// ==================== Utility Functions ====================

// freq_vec - count frequency of elements in vector
unordered_map<int, int> freq_vec(const vi &v) {
    unordered_map<int, int> freq;
    for (int x : v) freq[x]++;
    return freq;
}

// freq_str - count frequency of characters in string
unordered_map<char, int> freq_str(const string &s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    return freq;
}

// isPrime - checks if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// sieve - generates prime markings up to n
vi sieve(int n) {
    vi is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return is_prime;
}

// gcd and lcm
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// binary_search_custom - returns index or -1
int binary_search(const vi &a, int target) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

//XOR of n numbers
int xor_upto(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}

// Fast power (a^b % mod)
int power(int a, int b, int mod = 1000000007) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
// ==================== Solve Function ====================
void solve(){
    int t; cin >> t;
    while(t--){
        
    }
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int32_t main() {
    fast;
    solve();
    return 0;
}