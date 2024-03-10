#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<vector<int>> v;
    for(int i = 0; i < n; i++)
        v.push_back({a[i], b[i]});
    sort(v.begin(), v.end());

    int res = 1;
    int maxb = v[n - 1][1];
    int curMax = -1;
    int maxa = v[n - 1][0];
    int i = n - 2;
    while(i >= 0 && v[i][0] == v[i + 1][0]){
        res++;
        i--;
        maxb = max(maxb, v[i][1]);
    }
    while(i >= 0){
        if(v[i][0] != v[i + 1][0]){
            maxb = max(maxb, curMax);
            curMax = v[i][1];
        }
        else{
            curMax = max(curMax, v[i][1]);
        }
        if(v[i][0] != maxa){
            res += v[i][1] >= maxb;
        }
        i--;
    }
    cout << res << endl;
   return 0;
}