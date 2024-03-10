#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> f(vector<int>& v, int k){
    int n = v.size();
    vector<int> pref(n), suff(n), res;
    pref[0] = 1;
    for(int i = 1; i < n; i++){
        if(v[i - 1] >= v[i]) pref[i] = pref[ i - 1] + 1;
        else pref[i] = 1;
    }
    suff[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
        suff[i] = (v[i + 1] >= v[i] ? suff[i + 1] + 1 : 1);
    for(int i = 0; i < n;i++){
        if(pref[i] >= k + 1 && suff[i] >= k + 1)
            res.push_back(i + 1);
    }
    return res;
}
int main(){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> res = f(v, k);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}