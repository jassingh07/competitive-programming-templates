#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    int temp = t;
    while(t--){
        int s, d, k; cin >> s >> d >> k;
        int buns = 2 * (s + d);
        int cheese = 2 * d + s, patty = 2 * d + s;
        cout << "Case #" << temp - t << ": ";
        cout << ((buns >= k + 1 && cheese >= k) ? "YES" : "NO" ) << endl;
    }
    return 0;
}