#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll           long long int
int main()
{
    ll n; cin >> n;
    vector<ll> v(n);
    map<ll, vector<ll>> m;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        m[v[i]].push_back(i);
    }
    ll k; cin >> k;
    ll res = -1;
    auto it = m.begin();

    while(it != m.end()){
        vector<ll>&cur = it -> second;
        if(cur.size() < k) {
            it++;
            continue;
        }
        ll sz = cur.size();
        ll med_ind = sz % 2 ? sz / 2 : sz / 2 - 1;
        ll med = cur[med_ind];
        ll dis = 0;
        ll cost = 0;
        for(ll i = med_ind; i >= 0; i--){
            cost += med - cur[i] - dis++;
        }
        dis = 0;
        for(ll i = med_ind; i < sz; i++){
            cost += cur[i] - med - dis++;
        }
        if(res == -1) res = cost;
        else res = min(res, cost);
        it++;
    }
    cout << res << endl;
    
    return 0;
}