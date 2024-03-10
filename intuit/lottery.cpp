#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums){
    int n = nums.size();
    set<int> s(nums.begin(), nums.end());

    vector<int> v;
    for(auto i: s) v.push_back(i);
    n = v.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        int l = i, r = n - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(v[m] - v[i] == m - i){
                res = max(res, m - i + 1);
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
    }
    return res;
}
int main()
{
    int n; cin >> n;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << solve(v);
   return 0;
}