#include<bits/stdc++.h>
using namespace std;
vector<string> fun(vector<string>& requests, int k){
    map<int, string> index;
    map<string, int> str;
    int n = requests.size();
    for(int i = 0; i < n; i++){
        if(str.find(requests[i]) != str.end()){
            index.erase(str[requests[i]]);
            str[requests[i]] = i + 1;
            index[i + 1] = requests[i];
        }else{
            if(index.size() == k){
                string key = index.begin() -> second;
                index.erase(index.begin() -> first);
                str.erase(key);
            }
            str[requests[i]] = i + 1;
            index[i + 1] = requests[i];
        }
    }
    vector<string> res;
    for(auto p: index){
        res.push_back(p.second);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int k; cin >> k;
    vector<string> res = fun(v, k);
    for(auto &s: res) cout << s << " ";
}