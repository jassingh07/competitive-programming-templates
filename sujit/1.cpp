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


int dfs(vector<int>& arr, int x, int y, int z, vector< vector< vector< vector<int> > > >& dp,int i = 0){
    int n = arr.size();
    if(i == n) return 0;
    int &res = dp[i][x][y][z];
    if(res != -1) return res;
    res = 0;
    int one = 0, two = 0, three = 0;
    if(x) one = arr[i] + dfs(arr, x - 1, y, z, dp, i + 1);
    if(y && i + 2 <= n) two = arr[i] + arr[i + 1] + dfs(arr, x, y - 1, z, dp, i + 2);
    if(z && i + 3 <= n) three = arr[i] + arr[i + 1] + arr[i + 2] + dfs(arr, x, y, z - 1, dp, i + 3);
    int not_take = dfs(arr, x, y, z, dp, i + 1);
    return res = max({one, two, three, not_take});
}
int calculateProfit(vector<int>& arr, int x, int y, int z){
    int n = arr.size();
    vector< vector< vector< vector<int> > > > dp(n, vector< vector< vector<int> > >(x + 1, vector< vector<int>>(y + 1, vector<int>(z + 1, -1))));
    return dfs(arr, x, y, z, dp);
}
int main()
{
    int n; cin >> n;
    int x, y, z; cin >> x >> y >> z;
    vector<int> arr(n); fl(i, 0, n, 1) cin >> arr[i];
    cout << calculateProfit(arr, x, y, z);
   return 0;
}