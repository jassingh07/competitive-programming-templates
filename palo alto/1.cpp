#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (ll)(1e9 + 7)
vector<int> fun(int n, vector<int>& from, vector<int>& to, vector<int>& wt, int x){
        vector<vector<vector<int>>> adj(n);
        for(int i = 0; i < n - 1; i++){
            adj[from[i] - 1].push_back({to[i] - 1, wt[i]});
        }
        queue<vector<int>> q;
        q.push({0, x});
        vector<int> res(n);
        res[0] = x;
        vector<bool> vis(n, false);
        vis[0] = true;
        while(q.size()){
            int node = q.front()[0], mag = q.front()[1];
            q.pop();
            res[node] = mag;
            for(auto &neb: adj[node]){
                if(vis[neb[0]]) continue;
                vis[neb[0]] = true;
                q.push({neb[0], neb[1] * 1LL * mag % MOD});
            }
        }
        return res;
}
int main(){
    int n; cin >> n;
    int x; cin >> x;
    vector<int> to(n - 1), from(n - 1), wt(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> to[i];
    for(int i = 0; i < n - 1; i++) cin >> from[i];
    for(int i = 0; i < n - 1; i++) cin >> wt[i];
    return 0;
}