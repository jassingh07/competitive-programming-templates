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

ll getDiscountPairs(vector<int>&v, int x){
    ll res = 0, n = v.size();
    map<ll, ll> m;
    for(int i = n - 1; i >= 0; i--){
        v[i] %= x;
        res += m[x - v[i]];
        m[v[i]]++;
    }
    res += m[0] * (m[0] - 1) / 2;
    return res;

}
int main()
{
    int n, x; cin >> n >> x;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << getDiscountPairs(v, x);
   return 0;
}