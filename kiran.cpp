#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fl(i, m, n, p) for (ll i = m; i < n; i += p)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define vlli vector<ll>
#define testin ll t;  cin >> t; while (t--)
#define fel(x, v) for (auto x : v)
#define print(x, v) fel(x, v) cout << x << ' '
#define vplli vector<pair<ll, ll>>
#define vvlli vector<vlli>
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define endl "\n"

ll bin_to_dec(vlli n)
{
    vlli num = n;
    // reverse(all(num));
    ll dec_value = 0;
 
    ll base = 1;
 
    ll len = num.size();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i])
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

int main()
{
       testin{
            ll n, m, k;
            cin >> n >> m >> k;
            map<ll, ll> f;
            fl(i, 0, n, 1){
                vlli cur(m);
                fl(i, 0, m, 1) cin >> cur[i];
                ll first = bin_to_dec(cur);
                fl(i, 0, m, 1) cur[i] = !(cur[i]);
                ll second = bin_to_dec(cur);
                if(first == second) f[first]++;
                else {
                    f[first]++;
                    f[second]++;
                }
            }
            ll res = 0;
            for(auto p: f)
                res = max(res, p.second);
            cout << res << endl;
       }
}

