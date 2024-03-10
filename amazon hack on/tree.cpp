#include <bits/stdc++.h>
using namespace std;

vector<int> children;
int dfs(int node, vector<vector<int>>& adj, int par){
    int sub = 0;
    for(auto child: adj[node]){
        if(child == par) continue;
        sub += dfs(child, adj, node);
    }
    children[node] = sub;
    return sub + 1;
}
int main(){
    int v; cin >> v;
    children.resize(v, 0);
    vector<vector<int>> adj(v);
    for(int i = 1; i < v; i++) {
        int x; cin >> x;
        adj[x - 1].push_back(i);
    }
    dfs(0, adj, -1);
    for(auto cnt: children)
        cout << cnt << " ";
    return 0;
}