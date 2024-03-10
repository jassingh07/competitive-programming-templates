#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define MOD          (int)(1e9+7)

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll dfs(int start, int n, vector<vector<ll>>& dp, int target){
    if(n == 0){
        return start == target ? 1 : 0;
    }
    ll &res = dp[start + 1500][n];
    if(res != -1) return res;
    res = 0;
    if(start + 1 <= 1500) res = (res + dfs(start + 1, n - 1, dp, target)) % MOD;
    if(start - 1 >= -1500) res = (res + dfs(start - 1, n - 1, dp, target)) % MOD;
    res = (res + dfs(start, n - 1, dp, target)) % MOD;
    return res;
}

int countGoodArrays(vector<int>& arr){
    int n = arr.size();
    int prev = -1;
    ll res = 1;
    for(int i = 0; i < n; i++){
        if(arr[i]){
            if(prev == -1){
                res = (res * binpow(3, i, MOD));
                prev = i;
            }
            else{
                ll diff = arr[i] - arr[prev];
                if(diff > i - prev) return 0;
                vector<vector<ll>> dp(3001, vector<ll>(i - prev, -1));
                res = (res * dfs(0, i - prev - 1, dp, diff)) % MOD;
                prev = i;
            }
        }
        cout << res << endl;
    }
    res = (res * binpow(3, n - prev - 1, MOD));
    return res;
}
int main()
{
    int n; cin >> n;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << countGoodArrays(v);
   return 0;
}