#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define fl(i,m,n,p)  for(int i=m;i<n;i+=p)
#define bl(i,m,n,p)  for(int i=m,i>=n;i-=p)
#define pb(a)        push_back(a)
#define vi           vector<int>
#define all(v)       v.begin(),v.end()
#define vlli         vector<ll>
#define si           set<int>
#define MOD          (int)(1e9+7)
#define plli         pair<ll,ll>
#define testin       ll t;cin >> t; while (t--)
#define fel(x,v)     for(auto x:v)
#define print(x,v)   fel(x,v) cout<<x<<' '
#define FIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi          vector<vi>
#define vvlli        vector<vlli>
#define vc           vector<char>
#define vvc          vector<vc>
#define vb           vector<bool>
int dfs(vector<int>& arr, int th, vector<int>& dp, int i = 0){
    int n = arr.size();
    if(i == n) return 0;
    int maxE = 1;
    int &res = dp[i];
    if(res != -1) return res;
    res = INT_MAX;
    for(int j = i; j < min(i + th, n); j++){
        maxE = max(maxE, arr[j]);
        res = min(res, maxE + dfs(arr, th, dp, j + 1));
    }
    return res;
}
int calculateCost(vector<int>& arr, int threshold){
    int n = arr.size();
    vector<int> dp(n, -1);
    return dfs(arr, threshold, dp);
}
int main()
{
    int n; cin >> n;
    int th; cin >> th;
    vector<int> arr(n); fl(i, 0, n, 1) cin >> arr[i];
    cout << calculateCost(arr, th);
   return 0;
}