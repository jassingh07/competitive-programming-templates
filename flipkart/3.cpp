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


int main()
{
    int row, col; cin >> row >> col;
    vector<vector<int>> arr(row, vector<int>(col));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
    vector<vector<int>> interval(row);
    for(int i = 0; i < row; i++){
        int l = *min_element(all(arr[i]));
        int r = *max_element(all(arr[i]));
        interval.push_back({l, r});
    }
    sort(all(interval));
    
    int l = interval[0][0], r = interval[0][1];
    for(int i = 1; i < row; i++){
        int lc = interval[i][0], rc = interval[i][1];
        if(lc > r){
            r = lc;
            continue;
        }
        l = max(l, lc);
        r = min(r, lc);
    }
    cout << l << " " << r << endl;

    return 0;
}