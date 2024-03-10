#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
ll distinctSum(vector<int>& arr){
    ll n = arr.size();
    ll res = 0;
    map<ll, vector<ll>> m;
    for(int i = 0; i < n;i++)
        m[arr[i]].push_back(i);
    for(auto p: m){
        vector<ll>& cur = p.second;
        ll sz = cur.size();
        for(int i = 0; i < sz; i++){
            ll left = cur[i] - (i ? cur[i - 1] : -1);
            ll right = n - cur[i];
            res += left * right;
        }
    }
    return res;
}

int main()
{
    int n; cin >> n;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << distinctSum(v);
   return 0;
}