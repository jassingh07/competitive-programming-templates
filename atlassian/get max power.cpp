#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (ll)(1e9+7)
int getMaximumPower(vector<int>& arr, vector<int>& power){
    int n = arr.size(), k = power.size();
    sort(power.begin(), power.end());
    vector<ll> pref(n);
    pref[0] = arr[0];
    ll res = 0;
    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i];
    for(int i = 0; i < k / 2; i++){
        int l = power[i], r = power[k - i - 1];
        res += pref[r] - (l ? pref[l - 1] : 0);
    }
    return res % MOD;
}
int main(){
    int n, k; cin >> n >> k;
    vector<int> arr(n), power(k); 
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < k; i++) cin >> power[i];
    cout << getMaximumPower(arr, power);
    return 0;
}