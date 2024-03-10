#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        string s; cin >> s;
        if(s.length() > 26){
            cout << -1 << endl;
            continue;
        }
        vector<int> f(26, 0);
        for(int i = 0; i < n; i++) 
            f[s[i] - 'a']++;
        int res = 0;
        for(int i = 0;i < 26; i++){
            if(f[i]) res += f[i] - 1;
        }
        cout << res << endl;
    }
}