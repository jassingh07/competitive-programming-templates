#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.length();
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.size() && s[i] == s[st.top()]){
            s[i] = -1;
            s[st.top()] = -1;
            st.pop();
        }
        else
            st.push(i);
    }
    string res;
    for(int i = 0; i < n; i++)
        if(s[i] != -1)
            res.push_back(s[i]);
    cout << (res.length() ? res : "Empty String") << endl;
   return 0;
}