#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define testin       ll t;cin >> t; while (t--)


ll total, ans, cnInd;
ll sum(vector<vector<ll>>& adj,vector<ll>& val, map<pair<ll, ll>, ll>& cn, ll node, ll par){
    ll subSum = 0;
    for(auto &child: adj[node])
        if(child != par){
            ll childSum = sum(adj, val, cn, child, node);
            subSum += childSum;
            ll curAns = abs(total - childSum - childSum);
            if(curAns < ans){
                ans = curAns;
                cnInd = cn[{node, child}];
            }
            else if(curAns == ans && cn[{node, child}] < cnInd){
                cnInd = cn[{node, child}];
            }
        }
    return subSum + val[node];
}

int main()
{
    testin{
        cnInd = 1e9;
        ans = 1e12;
        total = 0;//global
        ll n; cin >> n;
        map<pair<ll, ll>, ll> cn;
        vector<vector<ll>> adj(n + 1);
        for(int i = 0; i < n - 1; i++){
            int a, b; cin >> a >> b;
            cn[{a, b}] = i + 1;
            cn[{b, a}] = i + 1;//bidirect
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<ll> val(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> val[i];
            total += val[i];
        }
        
        sum(adj, val,cn,  1, -1);
        cout << cnInd << endl;
    }
   return 0;
}