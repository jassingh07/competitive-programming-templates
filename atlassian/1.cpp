#include<bits/stdc++.h>
using namespace std;
#define ll           long long int

ll getMaximumSumOfHeights(vector<int>& maxHeight){
    int n = maxHeight.size();
    ll res = 0;
    //brute
    for(int i = 0; i < n; i++){
        int maxAch = maxHeight[i];
        //make left side pe max
        ll cur = maxAch;
        for(int j = i - 1; j >= 0; j--){
            maxAch = min(maxAch, maxHeight[j]);
            cur += maxAch;
        }
        maxAch = maxHeight[i];
        for(int j = i + 1; j < n; j++){
            cur += maxHeight[i];
        }
        res = max(res, cur);
        //make right side pe max

        cur = maxHeight[i];
        max
        cur = 0;

        res = max(res, cur);
    }
    return res;

}

int main()
{
    int n; cin >> n;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << getMaximumSumOfHeights(v);
   return 0;
}