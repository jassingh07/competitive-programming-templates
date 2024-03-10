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


int rev(int x){
    int res = 0;
    while(x){
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
void fun(int a, int b){
    int mina = 0, minb = 0, maxa = 0, maxb = 0;
    while(a){
        mina = mina * 10 + (a % 10 == 6 ? 5 : a % 10);
        maxa = maxa * 10 + (a % 10 == 5 ? 6 : a % 10);
        a /= 10;
    }
    while(b){
        minb = minb * 10 + (b % 10 == 6 ? 5 : b % 10);
        maxb = maxb * 10 + (b % 10 == 5 ? 6 : b % 10);
        b /= 10;
    }
    cout << rev(maxa) + rev(minb) << endl << rev(mina) + rev(maxb) << endl;
}

int main()
{
    // FIO
    string inputFilename = "C:/Users/DELL/OneDrive/Desktop/cp/input.txt";
    string outputFilename = "C:/Users/DELL/OneDrive/Desktop/cp/output.txt";
    // freopen(inputFilename.c_str(),"r",stdin);
    // freopen(outputFilename.c_str(),"w",stdout);
    int a, b; 
    cin >> a >> b;
    fun(a, b);
    return 0;
}