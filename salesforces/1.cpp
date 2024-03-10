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
int maximumNumberofBooks(vector<int>& nums){
    int next = 0, nextNext = 0, n = nums.size();
    for(int i = n - 1; i >= 0; i--){
        int cur = max(nums[i] + nextNext, next);
        nextNext = next;
        next = cur;
    }
    return next;
}
int main()
{
    int n; cin >> n;
    vector<int> v(n);
    fl(i, 0, n, 1) cin >> v[i];
    cout << maximumNumberofBooks(v);
   return 0;
}