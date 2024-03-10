#include<bits/stdc++.h>
using namespace std;

int solution(int n, int a[], int b[], int m){
    vector<set<int>> adj(n);
    queue<int> q;
    for(int i = 0; i < m; i++){
        adj[a[i]].insert(b[i]);
        adj[b[i]].insert(a[i]);
    }
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++)
        if(adj[i].size() <= 1) {
            q.push(i);
            vis[i] = true;
        }
    int seconds = 0;
    while(q.size()){
        seconds++;
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            int node = q.front();
            q.pop();
            for(auto neb: adj[node])
                if(!vis[neb]){
                    adj[neb].erase(adj[neb].find(node));
                    if(adj[neb].size() <= 1){
                        vis[neb] = true;
                        q.push(neb);
                    }
                }
        }
    }
    return seconds;
}
int main(){
    int n, m; cin >> n >> m;
    int a[m], b[m];
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    cout << solution(n, a, b, m);
    return 0;
}