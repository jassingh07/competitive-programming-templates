#include<bits/stdc++.h>
using namespace std;

int solution(int a[], int n, int x, int y){
    int res = 1e9;
    for(int i = n - 1; i >= 0; i--){
        if(i + y < n) a[i] += a[i + y];
        if(n - i >= x * y + 1 - x) res = min(res, a[i]);
    }
    return res;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int x, y; cin >> x >> y;
    cout << solution(a, n, x, y);
    return 0;
}