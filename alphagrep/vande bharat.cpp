#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define fl(i,m,n,p)  for(int i=m;i<n;i+=p)
#define pb(a)        push_back(a)
#define vi           vector<int>
#define all(v)       v.begin(),v.end()
#define vlli         vector<ll>
#define FIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi          vector<vi>
#define vvlli        vector<vlli>
pair<int, int> findNumberOfLIS(vlli& nums) {
       int n=nums.size();
       vector<int> dp(n,1),cnt(n,1);

       for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
        if(nums[j]<nums[i])
        {
            if(1+dp[j]>dp[i]) 
            {
                dp[i]=1+dp[j];
                cnt[i]=cnt[j];
            }
            
            else if(1+dp[j]==dp[i]) cnt[i]+=cnt[j];
        }

        int max_ind=max_element(dp.begin(),dp.end())-dp.begin();
        int result=0;

        for(int i=0;i<n;i++)
        if(dp[i]==dp[max_ind]) result+=cnt[i];
        return {dp[max_ind], result};
    }

int main()
{
    int n; cin >> n;
    vlli v(n);
    fl(i, 0, n, 1) cin >> v[i];
    reverse(all(v));
    pair<int, int> p = findNumberOfLIS(v);
    cout << p.first << endl << p.second << endl;
   return 0;
}