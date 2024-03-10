#include<bits/stdc++.h>
using namespace std;
int memo(vector<vector<int>>& a, vector<vector<int>>& dp, int i = 0, int net = 0){
    int n = a.size();
    if(i == n) return net >= 0 ? 0 : 2e9;
    int& res = dp[i][net + n];
    if(res != 2e9 + 1) return res;
    int take = a[i][1] + memo(a, dp, i + 1, min(n, net + a[i][0]));
    int not_take = memo(a, dp, i + 1, net - 1);
    return res = min(take, not_take);
}
int fun(vector<vector<int>>& a){
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(3 * n, 2e9 + 1));
    int total = 0;
    for(auto p: a)
        total += p[1];
    return total - memo(a, dp);
}

int main(){
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++) 
        cin >> v[i][0] >> v[i][1];
    cout << fun(v);
}