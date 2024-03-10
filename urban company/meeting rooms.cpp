#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define vi           vector<int>
#define all(v)       v.begin(),v.end()
#define vlli         vector<ll>
#define vvlli        vector<vlli>

ll dfs(vvlli& comb, vlli& next, vlli& dp, ll i){
    ll n = comb.size();
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    ll take = comb[i][2] + dfs(comb, next, dp, next[i]);
    ll not_take = dfs(comb, next, dp, i + 1);
    dp[i] = max(take, not_take);
    return dp[i];
}

int main()
{
    ll n; cin >> n;
    vlli people(n), start(n), end(n);
    vvlli comb;
    for(int i = 0; i < n; i++) cin >> people[i];
    for(int i = 0; i < n; i++) cin >> start[i];
    for(int i = 0; i < n; i++) cin >> end[i];

    map<ll, ll> st;
    for(int i = n - 1; i >= 0; i--) 
        if(end[i] >= start[i])
            comb.push_back({start[i], end[i], people[i]});
    sort(all(comb));
    n = comb.size();
    ll tot = 0;
    vlli next(n);
    for(int i = n - 1; i >= 0; i--){
        tot += comb[i][2];
        auto it = st.upper_bound(comb[i][1]);
        if(it == st.end()) 
            next[i] = n;
        else 
            next[i] = it -> second;
        st[comb[i][0]] = i;
    }
    vlli dp(n, -1);
    cout << tot - dfs(comb, next, dp, 0) << endl;
    
   return 0;
}