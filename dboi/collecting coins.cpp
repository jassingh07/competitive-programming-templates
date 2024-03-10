#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define vlli         vector<ll>


vlli solve(int n, int m, vector<int>& a, vector<int>& b, vector<int>& c){
    vector<vlli> v;
    for(int i = 0; i < b.size(); i++)
        v.push_back({b[i], c[i]});
    sort(v.begin(), v.end());
    for(int i = 1; i < b.size(); i++)
        v[i][1] += v[i - 1][1];
    for(int i = 0; i < b.size(); i++)
        b[i] = v[i][0];
    vlli cost;
    for(int i = 0; i < b.size(); i++)
        cost.push_back(v[i][1]);
    
    vlli res;
    for(int i = 0; i < a.size(); i++){
        int it = upper_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
        if(it == -1) 
            res.push_back(0);
        else  
            res.push_back(cost[it]);
    }
    return res;
}
int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i];
    vlli res = solve(n, m, a, b, c);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
   return 0;
}