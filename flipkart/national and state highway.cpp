#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define vlli 		vector<ll>
#define vvlli       vector<vlli>

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

int main()
{ 
    ll n, m; cin >> n >> m; 
    vector<vvlli> adj(n + 1);
	vvlli ned;
    for(int i = 0; i < m; i++) {
        ll a, b, sd, nd;
        cin >> a >> b >> sd >> nd;
        adj[a].push_back({b, sd});
        adj[b].push_back({a, sd});
		ned.push_back({a, b, nd});
    }
    ll src, des; cin >> src >> des;
	vector<ll> toSrc = djikstra(src, adj);
	vector<ll> toDes = djikstra(des, adj);
	ll res = toSrc[des];
	for(auto v: ned){
		int a = v[0], b = v[1], d = v[2];
		res = min({res, d + toSrc[a] + toDes[b], d + toSrc[b] + toDes[a]});
	}
    cout << (res >= 1e9 ? -1 : res) << endl;
   return 0;
}