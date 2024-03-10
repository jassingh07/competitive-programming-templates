#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define all(v)       v.begin(),v.end()


int main()
{
    int n, m; cin >> n >> m;
    vector<int> work(n, 0);
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        work[a - 1]++;
    }
    sort(all(work));
    int l = 0, r = m;
    ll res = m;
    while(l <= r){
        int days = (l + r) / 2;
        ll rem = 0;
        for(int i = n - 1; i >= 0; i--){
            if(work[i] > days){
                rem += work[i] - days;
            }
            else{
                ll afford = days - work[i];
                rem -= afford / 2;
            }
        } 
        if(rem > 0)
            l = days + 1;
        else{
            r = days - 1;
            res = days;
        }
    }

    cout << res << endl;
   return 0;
}