#include<bits/stdc++.h>
using namespace std;
int memo(vector<string>& words, int w, int i, int left, vector<vector<int>>& dp){
    int n = words.size();
    if(i == n) return left == w ? 0 : (left + 1) * (left + 1);
    if(words[i].length() > w) return 1e9;
    int& res = dp[i][left + 1];
    if(res != -1) return res;
    res = 0;
    int keep = 1e9;
    if(left >= (int)words[i].length())
        keep = memo(words, w, i + 1, left - words[i].length() - 1, dp);
    int endLine = 1e9;
    if(left != w)
        endLine =  (left + 1) * (left + 1) + memo(words, w, i, w, dp);
    
    return res = min(keep, endLine);
}

int main()
{
    int w; cin >> w;
    string s;
    vector<string> words;
    string temp;
    while(cin >> temp)
        words.push_back(temp);
    
    int n = words.size();
    vector<vector<int>> dp(n, vector<int>(w + 2, -1));
    int res = memo(words, w, 0, w, dp);
    cout << (res == 1e9 ? -1 : res) << endl;
    return 0;
}