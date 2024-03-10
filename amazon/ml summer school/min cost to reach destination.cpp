#include<bits/stdc++.h>
using namespace std;
int minimumCost(int n, int arr[]){
    int dp[3] = {0, (int)1e9, (int)1e9};
    for(int i = n - 2; i >= 0; i--){
        int cur = 1e9;
        if(i + 1 < n) cur = min(cur, abs(arr[i + 1] - arr[i]) + dp[0]);
        if(i + 3 < n) cur = min(cur, abs(arr[i + 3] - arr[i]) + dp[2]);
        dp[2] = dp[1];
        dp[1] = dp[0];
        dp[0] = cur;
    }
    return dp[0];
}
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << mini(n, arr);
   return 0;
}