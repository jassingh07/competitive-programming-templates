#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define fl(i,m,n,p)  for(int i=m;i<n;i+=p)
#define bl(i,m,n,p)  for(int i=m,i>=n;i-=p)
#define pb(a)        push_back(a)
#define vi           vector<int>
#define all(v)       v.begin(),v.end()
#define vlli         vector<ll>
#define si           set<int>
#define MOD          (int)(1e9+7)
#define plli         pair<ll,ll>
#define testin       ll t;cin >> t; while (t--)
#define fel(x,v)     for(auto x:v)
#define print(x,v)   fel(x,v) cout<<x<<' '
#define FIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi          vector<vi>
#define vvlli        vector<vlli>
#define vc           vector<char>
#define vvc          vector<vc>
#define vb           vector<bool>
int getMaxCount(vector<int>& people, vector<char>& status){
    int n = people.size();
    set<int> s;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(status[i] == '+'){
            if(s.find(people[i]) != s.end()) return -1;
            s.insert(people[i]);
        }
        else {
            if(s.find(people[i]) == s.end()) return -1;
            s.erase(s.find(people[i]));
        }
        res = max(res, (int)s.size());
    }
    return res;
}

int main()
{
    int n; cin >> n;
    vector<int> people(n);
    vector<char> status(n);
    for(int i = 0; i < n; i++) cin >> people[i];
    for(int i = 0; i < n; i++) cin >> status[i];
    // cout << "h";
    cout << getMaxCount(people, status);
   return 0;

}