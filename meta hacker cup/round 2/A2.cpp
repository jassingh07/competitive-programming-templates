#include <bits/stdc++.h>
#include <unordered_set>
#include <fstream>
// #include <bit>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
using namespace std;

#define ll long long int
#define fl(i, m, n, p) for (ll i = m; i < n; i += p)
#define bl(i, m, n, p) for (ll i = m, i >= n; i -= p)
#define pb(a) push_back(a)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define vlli vector<ll>
#define vd vector<double>
#define si set<int>
#define MOD (ll)(1e9 + 7)
#define MOD2 (ll)(998244353)
#define plli pair<ll, ll>
#define testin ll t;  cin >> t; while (t--)
#define fel(x, v) for (auto x : v)
#define print(x, v) fel(x, v) cout << x << ' '
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vvi vector<vi>
#define vpi vector<pair<int, int>>
#define vplli vector<pair<ll, ll>>
#define pi pair<int, int>
#define vvlli vector<vlli>
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define endl "\n"
#define MIN_HEAP(T) priority_queue<T, vector<T>, greater<T>>
#include <numeric>
#define sz(T) (ll)(T.size())

// using namespace __gnu_pbds;
// template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// https://codeforces.com/blog/entry/68809

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i : x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define pr(x...) cout << "[" << #x << "] = ["; _print(x);
#else
#define pr(x...)
#endif

struct custom_hash
{
  static uint64_t splitmix64(uint64_t x)
  {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
 
  size_t operator()(uint64_t x) const
  {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <typename T1, typename T2> 
using safe_map = unordered_map<T1, T2, custom_hash>;

// https://codeforces.com/blog/entry/62393

// struct best_hash {
//   static uint64_t splitmix64(uint64_t x) {

//     x += 0x9e3779b97f4a7c15;
//     x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//     x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//     return x ^ (x >> 31);
//   }

//   size_t operator()(uint64_t x) const {
//     static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//     return splitmix64(x + FIXED_RANDOM);
//   }
// };


class DSU
{ // inverse ackermann, average complexity ~= 4 i.e constant for each query on good value of n also
public:
    vector<ll> parent, size;
    DSU(ll n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        fl(i, 1, n + 1, 1) parent[i] = i;
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



vlli sieve(int n)
 {
    vlli res(n+1, 0);
    for(ll i = 2;i <= n; i++)
        if(!res[i]){
            for(ll j = i*i; j <= n; j += i)
                if(!res[j]) 
                    res[j]=i;
            res[i] = i;
        }
    return res;
 }


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vb binary(ll x){
    vb res;
    while(x){
        res.pb(x % 2);
        x /= 2;
    }
    return res;
}

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

// ll log2_floor(unsigned long i) {
//     return std::bit_width(i) - 1;
// }
// galtiya:
// unsigned long int a=2; cout<<(-1 < a - 1); ALWAYS REMEMBER
// max, min ale ques dp ch mod end ch lena
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int cnt(vector<vector<char>> &v, vector<vb> &vis, set<pair<int, int>> &khali, int i, int j){
    int r = v.size(), c = v[0].size();
    if(i < 0 || j < 0 || i == r || j == c || v[i][j] == 'B')
        return 0;
    if(v[i][j] == '.') {
        khali.insert({i, j});
        return 0;
    }
    if(vis[i][j]) return 0;
    vis[i][j] = true;
    int res = 0;
    fl(k, 0, 4, 1){
        ll nx = i + dx[k], ny = j + dy[k];
        res += cnt(v, vis, khali,nx, ny);
    }
    return 1 + res;
}
int main()
{
    // FIO
    string inputFilename = "C:/Users/DELL/OneDrive/Desktop/cp/input.txt";
    string outputFilename = "C:/Users/DELL/OneDrive/Desktop/cp/output.txt";
    freopen(inputFilename.c_str(),"r",stdin);
    freopen(outputFilename.c_str(),"w",stdout);
    ll t; cin >> t;
    ll temp = t;
    while(t--){
        ll r, c;
        cin >> r >> c;
        vector<vector<char>> v(r, vector<char>(c));
        fl(i, 0, r, 1)
            fl(j, 0, c, 1) 
                cin >> v[i][j];
        vector<vb> vis(r, vb(c,false));
        int res = 0;
        map<pair<int, int>, int> mp;
        fl(i, 0, r, 1)
            fl(j, 0, c, 1){
                // if(i == 0 && j == 1)
                //     cout << check(v, vis, dfsvis, i, j);
                if(v[i][j] == 'W' && !vis[i][j]){
                    set<pair<int, int>> khali;
                    int nodes = cnt(v, vis, khali, i, j);
                    if(khali.size() == 1){
                        int x = khali.begin() -> first;
                        int y = khali.begin() -> second;
                        mp[{x, y}] += nodes;
                        res = max(res, mp[{x, y}]);
                    }
                }
            }
        cout << fixed << "Case #" << temp - t << ": " << res << endl;
    }
    return 0;
}