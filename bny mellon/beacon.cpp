#include<bits/stdc++.h>
using namespace std;
#define ll           long int
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

long beacon_signal(int x1, int y1, int x2, int y2, int xl, int yl, int R){
    ll res = 0;
    for(int i = xl - R; i <= xl + R; i++){
        if(i >= x1 && i <= x2){
            ll yu = (ll)sqrt(R * 1LL * R - (xl - i) * 1LL * (xl - i))  + yl;
            ll yd = (ll)sqrt(R * 1LL * R - (xl - i) * 1LL * (xl - i))  - yl;
            if(yd > y2 || yu < y1) continue;
            if(yd <= y2 && yd >= y1) res += y2- yd;
            else res += yu - y1;
        }
    }
    return res;
}
int main()
{
    int x1, y1, x2, y2, xl, yl, r; cin >> x1 >> y1 >> x2 >> y2 >> xl >> yl >> r;
    cout << beacon_signal(x1, y1, x2, y2, xl, yl, r);
   return 0;
}