#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> getMeanRankCount(vector<int>& rank){
    int n = rank.size();
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = i; j < n; j++){
            sum += rank[j];
            ll num_ele = j - i + 1;
            if(sum % (num_ele) == 0)
                res[sum / num_ele - 1]++;
        }
    }
    return res;
}
int main()
{
    int n; cin >> n; 
    vector<int> in(n); for(int i = 0; i < n; i++) cin >> in[i];
    vector<int> res = getMeanRankCount(in);
    for(int i = 0; i < n; i++) cout << res[i] << " ";
   return 0;
}