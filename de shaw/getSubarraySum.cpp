#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll memo(vector<int>& arr, vector<vector<ll>>& dp, int i = 0, int part = 0){
    int n = arr.size();
    if(i == n) return part == 4 ? 0 : -1e17;
    if(part >= 4) return -1e17;

    ll &res = dp[i][part];
    if(res != -1e18) return res;
    ll cur = 0;
    for(int j = i; j < n; j++){
        cur += (part % 2 ? -1 : 1) * arr[j];
        res = max(res, cur + memo(arr, dp, j + 1, part + 1));
    }
    return res;
}
ll getSubarraySum(vector<int>& arr){
    int n = arr.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(5, -1e18));
    return memo(arr, dp);
}
int main(){
    int n; cin >> n;
    vector<int> v(n); 
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << getSubarraySum(v);
    return 0;
}