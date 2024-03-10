#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define vlli         vector<ll>
#define vvlli        vector<vlli>

vector<ll> djikstra(int source, vector<vvlli>& adj){
	ll n = adj.size() - 1;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll>>> pq;
	vector<ll> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,source)
	while( !pq.empty() ){
		ll dist = pq.top().first;
		ll prev = pq.top().second;
		pq.pop();

		for(auto& neb: adj[prev]){
			ll next = neb[0];
			ll nextDist = neb[1];
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
    return distTo;
}

ll minCostPath(int n, vector<int>& from, vector<int>& to, vector<int>& wt, int x, int y){
    vector<vvlli> adj(n + 1);
    for(int i = 0; i < to.size(); i++){
        adj[to[i]].push_back({from[i], wt[i]});
        adj[from[i]].push_back({to[i], wt[i]});
    }
    vlli xdis = djikstra(x, adj), ydis = djikstra(y, adj);
    return min(xdis[1] + ydis[x] + ydis[n], ydis[1] + xdis[y] + xdis[n]);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> from(k), to(k), wt(k);
    for(int i = 0; i < k; i++) cin >> from[i];
    for(int i = 0; i < k; i++) cin >> to[i];
    for(int i = 0; i < k; i++) cin >> wt[i];
    int x, y;
    cin >> x >> y;
    cout << minCostPath(n, from, to, wt, x, y);
   return 0;
}