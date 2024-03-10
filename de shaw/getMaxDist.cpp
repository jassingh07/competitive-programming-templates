#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vlli vector<ll>

ll getMaxDist(vlli& st, ll d){
    sort(st.begin(), st.end());
    ll l = 0, r = 1e18, res= -1, n = st.size();
    while(l <= r){
        ll m = (l + r) / 2;
        ll cur = st[0];
        bool pos = true;
        for(ll i = 1; i < n; i++){
            if(cur + m > st[i] + d){
                pos = false;
                break;
            }
            cur = max(cur + m, st[i]);
        }
        if(pos){
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}
int main(){
    ll n, d; cin >> n >> d;
    vlli v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << getMaxDist(v, d);
}