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

int solve(int n, int k, vector<int>& nums){
    unordered_map<int, int> m;
    for(auto i: nums) m[i]++;

    int res = 0;
    for(int i = 1; i <= 1e6; i++){
        int cur = 0;
        for(int j = 0; j <= 1e6; j+= i)
            cur += m.find(j) != m.end() ? m[j] : 0;

        if(cur >= k)
            res = i;
    }
    return res;
}

int main()
{
    int n; cin >> n;
    int k; cin >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << solve(n, k, v);
   return 0;
}