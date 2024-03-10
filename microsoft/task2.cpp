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

int dfs(vector<vector<int>>& khali, vector<vector<int>>& bhare, vector<int> extra, int i, int mask){
    int n = khali.size();
    if(i == n) return 0;
    int res = 1e9;
    for(int j = 0; j < bhare.size(); j++)
        if( (mask ^ (1 << j)) && (extra[j])){
            extra[j]--;
            res = min(res, abs(bhare[j][0] - khali[i][0]) + abs(bhare[j][1] - khali[i][1]) + dfs(khali, bhare, extra, i + 1, mask & (1 << j)) );
            extra[j]++;//backtrack
        }
    return res;
}
int solution(vector<vector<int>>& mat){
    vector<vector<int>> khali, bhare;
    vector<int> val;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            if(mat[i][j] == 0)
                khali.push_back({i, j});
            else if(mat[i][j] > 1){
                bhare.push_back({i, j});
                val.push_back(mat[i][j] - 1);
            }
        }
    return dfs(khali, bhare, val, 0, 0);
}
int main()
{
    vector<vector<int>> mat(3, vector<int>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> mat[i][j];
    cout << solution(mat);
   return 0;
}