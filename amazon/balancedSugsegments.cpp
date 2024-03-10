#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int f(vector<int>& v){
    int n = v.size();
    vector<ll> pref(n);
    pref[0] = v[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + v[i];
    map<int, int> prev;
    int res = 0;
    for(int i = 0; i < n; i++){
        // cout << prev[v[i]] << " ";
        if(prev.count(v[i]) && pref[i - 1] - pref[prev[v[i]]] == v[i]){
            res ++;
        }
        if(i >= 2 && v[i] == v[i - 1] && v[i - 1] == v[i - 2])
            res++;//edge
        prev[v[i]] = i;
        // cout << i << " " << res<< endl;
    }
    return res;
}
int main(){
    int n; cin >> n;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    cout << f(v);
    return 0;
}