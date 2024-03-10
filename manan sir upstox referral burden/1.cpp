#include<bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int>& tc){
    int n = tc.size();
    for(auto &ele: tc){
        int res = 1;
        int prev = 0;
        for(int i = 0; i < 32; i++){
            int cur = (1 << i);
            if((ele & cur) == cur){
                res += prev;
                prev = cur;
            }
        }
        ele -= res;
    }
    return tc;
}
int main(){
    int t; cin >> t;
    vector<int> tc;
    while(t--){
        int n; cin >> n;
        tc.push_back(n);
    }
    tc = fun(tc);
    for(auto& ele: tc) cout << ele << " ";
    return 0;
}