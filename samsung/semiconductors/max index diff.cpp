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

int MaxIndexDiff(int* arr, int n){
    
    int res = 0;
    for(int i = 0; i < n; i++){
        //right end n - 1
        int l = i + 1, r = n - 1;//moving the left end
        int ind = i + 1;//sab to door wala ind
        while(l <= r){
            int m = (l + r) / 2;
            int rangeMax = 0;
            if(rangeMax > arr[i]){
                ind = m;
                l = m + 1;
            }
            else r = m - 1;
        }

        if(arr[ind] > arr[i])
            res = max(res, ind - i);
    }
    return res;
}

int main(){
    int n; cin >> n;
    int * arr = new 
    fl(i, 0, n, 1)
    return 0;
}