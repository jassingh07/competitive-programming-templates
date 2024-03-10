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
int main()
{
   return 0;
}
vector<long> mazeGame(vector<long> t, vector<int> endpoint1, vector<int> endpoint2, vector<int> edgeLength)
{
    int n = t.size();
    vector<long> ans(n, 1e18);
    if(t[0] != -1)
        ans[0] = 0;
    vector<pair<long, long> > adj[n];
    for (int i = 0; i < endpoint1.size(); i++)
    {
        adj[endpoint1[i] - 1].push_back(make_pair(endpoint2[i] - 1, edgeLength[i]));
        adj[endpoint2[i] - 1].push_back(make_pair(endpoint1[i] - 1, edgeLength[i]));
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > p;
    if(t[0] != -1) p.push(make_pair(0, 0));

    while (p.empty() != 1)
    {
        auto it = p.top();
        p.pop();
      
        for (auto i : adj[it.second])
        {
            if (ans[i.first] >= i.second + it.first && t[i.first] > i.second + it.first)
            {
                ans[i.first] = i.second + it.first;
                p.push(make_pair(i.second + it.first, i.first));
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1e18)
            ans[i] = -1;
    }

    return ans;
}