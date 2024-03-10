#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define fl(i,m,n,p)  for(int i=m;i<n;i+=p)
#define bl(i,m,n,p)  for(int i=m,i>=n;i-=p)
#define pb(a)        push_back(a)
#define vi           vector<int>
#define all(v)       v.begin(),v.end()
#define vlli         vector<ll>
#define si           set<int>
#define MOD          (int)(1e9+7)
#define plli         pair<ll,ll>
#define testin       ll t;cin >> t; while (t--)
#define fel(x,v)     for(auto x:v)
#define print(x,v)   fel(x,v) cout<<x<<' '
#define vvi          vector<vi>

vi sieve(int n)
 {
    vi res(n+1, 0);
    for(ll i = 2;i <= n; i++)
        if(!res[i]){
            for(ll j = i*i; j <= n; j += i)
                if(!res[j]) 
                    res[j]=i;
            res[i] = i;
        }
    return res;
 }

vector<int> get_closest_pair(vector<int>& nums){
    int n = nums.size();
    vvi prime, non_prime;
    vi isPrime = sieve(1e6);
    fl(i, 0, n, 1) isPrime[nums[i]] == nums[i] ? prime.push_back({nums[i], i}) : non_prime.push_back({nums[i], i});

    vector<int> res;
    int diff = INT_MAX;
    ll plen = prime.size(), nplen = non_prime.size();
    sort(all(non_prime));
    for(int i = 0; i < plen; i++){
        auto it = lower_bound(all(non_prime), prime[i]) - non_prime.begin();
        int left = INT_MAX, right = INT_MAX;
        if(it) {
            left = abs(non_prime[it - 1][0] - prime[i][0]);
            vector<int> cur = {non_prime[it - 1][1], prime[i][1]};
            sort(all(cur));
            if(left < diff){
                diff = left;
                res = cur;
            }
            else if(left == diff){
                if(cur[0] < res[0]) 
                    res = cur;
                else if(cur[0] == res[0] && cur[1] <= res[1])
                    res = cur;
            }
        }
        if(it != nplen){
            right = abs(non_prime[it][0] - prime[i][0]);
            vector<int> cur = {non_prime[it][1], prime[i][1]};
            sort(all(cur));
            if(right < diff){
                diff = right;
                res = cur;
            }
            else if(right == diff){
                if(cur[0] < res[0]) 
                    res = cur;
                else if(cur[0] == res[0] && cur[1] <= res[1])
                    res = cur;
            }
        }
    }
    if(res.size()){
        res[0] = nums[res[0]];
        res[1] = nums[res[1]];
    }
    return res;
}
int main()
{
    int n; cin >> n;
    vector<int> v(n);
    fl(i, 0, n, 1) cin >> v[i];
    vi res = get_closest_pair(v);
    print(x, res);
   return 0;
}