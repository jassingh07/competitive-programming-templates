#include<bits/stdc++.h>
using namespace std;
int find_min_diff(vector<int>& v, int n, int k){
    sort(v.begin(), v.end());
    int res = 1e9;
    for(int i = k - 1; i < n; i++)
        res = min(res, v[i] - v[i - k + 1]);
    return res;
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin >> v[i];
    int k; cin >> k;
    cout << find_min_diff(v, n, k);
    
    return 0;
}