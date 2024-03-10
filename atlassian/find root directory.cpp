#include<bits/stdc++.h>
using namespace std;
#define parMov "../"
#define remain "./"
#define root "123"
int minimumSteps(vector<string>& v){
    int n = v.size();
    map<string, string> par;
    string cur = root;//named as root
    for(int i = 0; i < n; i++){
        if(v[i] == parMov){
            cur = par[cur];
        }else if(v[i] == remain){
            continue;
        }else{
            v[i].pop_back();
            par[v[i]] = cur;
            cur = v[i];
        }
    }
    int moves = 0;
    while(cur != root){
        cur = par[cur];
        moves++;
    }
    return moves;
}
int main(){
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << minimumSteps(v);
    return 0;
}