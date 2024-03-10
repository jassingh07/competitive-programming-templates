#include<bits/stdc++.h>
using namespace std;


vector<int> fun(vector<string>& a, vector<string>& b){
    vector<int> res;
    for(int i = 0; i < a.size() ;i++){
        vector<int> cnt(26, 0), tar(26, 0);
        if(a[i].size() != b[i].size()){
            res.push_back(0);
            continue;
        }
        for(int j = 0; j < a[i].size(); j++){
            cnt[a[i][j] - 'a']++;
            tar[b[i][j] - 'a']++;
        }
        
        bool possible = true;
        for(int k = 0; k < 26; k++){
            if( (cnt[k] < tar[k] )|| (cnt[k] - tar[k] == 1) ) {
                // cout << i << " " << (char)(k + 'a') << " " << cnt[k] << " " << tar[k]  << endl;
                possible = false;
                break;
            }
            if(cnt[k] > tar[k])
                cnt[k + 1] += cnt[k] - tar[k];
        }
        res.push_back(possible);
    }
    return res;
}  
int main(){
    int n; cin >> n;
    vector<string> words1(n), words2(n);
    for(int i = 0; i < n; i++) cin >> words1[i];
    for(int i = 0; i < n; i++) cin >> words2[i];
    vector<int> res = fun(words1, words2);
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    return 0;
}