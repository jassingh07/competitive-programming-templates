#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> readBooks(vector<ll>& a, vector<ll>& b){
    ll m = a.size(), n = b.size();
    vlli pref(m);
    map<ll, ll> mp;
    pref[0] = a[0];
    mp[pref[0]] = 0;
    for(int i = 1; i < m; i++){
        pref[i] += pref[i - 1] + a[i];
        if(mp.find(pref[i]) == mp.end()) mp[pref[i]] = i;
    }
    for(int i = 0; i < n; i++){
        ll cur = b[i];
        ll cnt = 0;
        if(pref[m - 1] > 0) {
            cnt = b[i] / pref[m - 1] * m;
            cur -= b[i] / pref[m - 1] * pref[m - 1];
        }
        if(!cur) {
            b[i] = cnt;
            continue;
        }
        auto it = mp.lower_bound(cur);
        if(it != mp.end()) {
            cnt += it -> second + 1;
            b[i] = cnt;
        }
        else{
            b[i] = -1;
        }
    }
    return b;
}
