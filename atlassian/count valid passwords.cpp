#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (ll)(1e9+7)

int countValidPasswords(int n, int k){
    ll res = 0;
    vector<ll> dp(n + 1, 1);
    ll win = 1;
    for(int i = n - 1; i >= 0; i--){
        if(i + k  <= n) {
            win = (win - dp[i + k]);
            if(win < 0) win += MOD;
        }
        dp[i] = (25 + (i == 0)) * win % MOD;
        win = (win + dp[i]) % MOD;
    }
    return dp[0];
}

int main(){
    int n, k; cin >> n >> k;
    cout << countValidPasswords(n, k);
    return 0;
}