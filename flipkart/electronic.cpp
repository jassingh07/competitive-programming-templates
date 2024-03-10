#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main()
{
    string s; cin >> s;
    int k; cin >> k;
    int cur = 0, res = 0;
    for(int i = 0; i < s.length(); i++){
        cur += isVowel(s[i]);
        if(i - k >= 0)
            cur -= isVowel(s[i - k]);
        res = max(res, cur);
    }
    cout << res << endl;
   return 0;
}