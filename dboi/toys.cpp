#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k, vector<int>& arr){
    vector<int> req;
    for(int i = 0; i < n; i++){
        int r = arr[i] % m == 0 ? 0 : (arr[i] / m + 1) * m - arr[i];
        req.push_back(r);
    }
    sort(req.begin(), req.end());
    int res = 0;
    for(int i = 0; i < n; i++){
        if(k - req[i] >= 0) {
            res++;
            k -= req[i];
        }
    }
    return res;
}

int main()
{
    int n, m, k;cin >> n >> m >> k;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << solve(n, m, k, v);
   return 0;
}