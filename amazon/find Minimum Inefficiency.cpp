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

int findMinimumInefficiency(string& serverType){
    int n = serverType.size();
    int res = 0;
    int prev = -1;
    for(int i = 0; i < n; i++){
        if(serverType[i] == '0' || serverType[i] == '1'){
            if(prev != -1)
                res += serverType[i] != serverType[prev];
            prev = i;
        }
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << findMinimumInefficiency(s);
   return 0;
}