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
#define FIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi          vector<vi>
#define vvlli        vector<vlli>
#define vc           vector<char>
#define vvc          vector<vc>
#define vb           vector<bool>

class DSU
{ // inverse ackermann, average complexity ~= 4 i.e constant for each query on good value of n also
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);
        fl(i, 0, n, 1) parent[i] = i;
    }
    int get(int v)
    {
        return parent[v] = (parent[v] == v ? v : get(parent[v]));
    }
    void Union(int a, int b)
    {
        a = get(a);
        b = get(b);
        if (size[a] < size[b])
            swap(a, b); // i.e always making b smaller tree
        // now join b to a
        parent[b] = a;
        size[a] += size[b]; // b rooted tree joined in a
    }
};

vlli sieve(ll n)
{
    vlli res(n + 1, 0);
    res[0] = 1;//0 not prime
    res[1] = 1;// 1 not prime
    for (ll i = 2; i < n + 1; i++)
        for (ll j = i * i; j <= n; j += i)
                if(!res[j]) res[j] = i;
    // only 0 marked are prime
    return res;
}

class segtree
{
    ll n;
    vlli ds;

public:
    segtree(ll n)
    {
        this->n = n;
        ds.resize(4 * n, -200);
    }
    void build(vlli &arr, ll low, ll high, ll ind)
    {
        if (low == high)
        {
            ds[ind] = arr[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(arr, low, mid, 2 * ind + 1);
        build(arr, mid + 1, high, 2 * ind + 2);
        ds[ind] = ds[2 * ind + 1] | ds[2 * ind + 2];
    }
    ll query(ll ind, ll low, ll high, ll l, ll r)
    {
        if (low >= l && high <= r)
            return ds[ind];

        if (low > r || high < l)
            return 0; // not to be added
        // if overlapping in any manner branch
        int mid = (low + high) / 2;
        return query(2 * ind + 1, low, mid, l, r) | query(2 * ind + 2, mid + 1, high, l, r);
    }
    ll update(ll val, ll ind, ll low, ll high, ll idx)
    {
        int mid = (low + high) / 2;
        if (low == high && low == idx)
        {
            int temp = ds[ind];
            ds[ind] = val;
            return ds[ind] - temp;
        }
        int ret;
        if (idx > mid)
            ret = update(val, 2 * ind + 2, mid + 1, high, idx);
        else
            ret = update(val, 2 * ind + 1, low, mid, idx);

        ds[ind] += ret;
        return ret;
    }
};

ll log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
class sparse{//rsq
    public:
    vvlli st;
    ll k;
    sparse(vlli& v){
        ll n = v.size();
        k = log2_floor(n) + 1;
        st.resize(n, vlli(k));
        fl(i, 0, n, 1) st[i][0] = v[i];//base
        fl(i, 1, k, 1)
            for(ll j = 0; j + (1 << i) - 1 < n; j++)
                st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
    ll query(ll l, ll r){//l,r -> 0 based indexing
        return min(st[l][log2_floor(r - l + 1)], st[r + 1 - (1 << log2_floor(r - l + 1))][log2_floor(r - l + 1)]);
    }
};
int main()
{
   return 0;
}