#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool checkHex(string s)
{
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        char ch = s[i];
 
        if ((ch < '0' || ch > '9') &&
            (ch < 'A' || ch > 'F'))
           return false;
    }
    return true;
}
bool checkNum(string s) {
   for( int i = 0; i < s.length(); i++ ) {
      if( !isdigit( s[i] )) {
         return false;
      }
   }
   return true;
}
vector<string> adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    vector<string> v;
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        v.push_back(word);
    }
    return v;
}

string solve(string& ip){
    char v4del = '.';
    char v6del = ':';
    vector<string> v;
    if(ip.find(".") != string::npos){
        v = adv_tokenizer(ip, '.');
        if(v.length() != 4) return "Neither";
        for(int i = 0; i < 4; i++)
            if(checkNum(v[i])){
                if(v[i].size() > 1 && v[i][0] == '0') return "Neither";
                ll num = stoll(v[i]);
                if(num < 0 || num > 255) return "Neither";
            }
            else 
                return "Neither";
        return "IPv4"
    }
    else{
        v = adv_tokenizer(ip, ':');
        if(v.length() != 8) return "Neither";
        for(int i = 0; i < 8; i++)
            if(checkHex(v[i]) && v[i].length() <= 4){
                continue;
            }
            else return "Neither";
        return "IPv6"
    }
}

int main()
{
   return 0;
}