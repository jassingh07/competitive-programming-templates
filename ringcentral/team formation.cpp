#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
ll teamFormation(vector<int>& scores, int team_size, int k){
    int n = scores.size();
    int l = k - 1, r = n - k;
    ll res = 0;
    if(l >= r){
        sort(scores.begin(), scores.end());
        for(int i = n - 1; i >= 0 && team_size ; i--, team_size--)
            res += scores[i];
        return res;
    }
    priority_queue<vector<int>> pq;//max heap
    for(int i = 0; i <= l; i++) 
        pq.push({scores[i], -i});
    for(int i = r; i < n; i++)
        pq.push({scores[i], -i});

    while(team_size--){
        res += pq.top()[0];
        int ind = -pq.top()[1];
        pq.pop();
        if(r - l > 1){
            if(ind <= l){
                l++;
                pq.push({scores[l], -l});
            }
            else{
                r--;
                pq.push({scores[r], -r});
            }
        }
    }
    return res;

}
int main()
{
    int n; cin >> n;
    vector<int> in(n); for(int i = 0; i < n;i++) cin >> in[i];
    int sz, k; cin >> sz >> k;
    cout << teamFormation(in, sz, k);
   return 0;
}