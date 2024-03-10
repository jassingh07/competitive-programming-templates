#include<bits/stdc++.h>
using namespace std;
#define ll           long long int

ll totalDistortion(int issues[][5], int n){
    ll res = 0;
    ll prev = 0;
    for(int j = 0; j < 5; j++) prev += issues[0][j];

    for(int i = 1; i < n; i++){
        ll cur = 0;
        for(int j = 0; j < 5; j++) cur += issues[i][j];
        if(cur > prev){
            res += cur - prev;
        }
        prev = cur;
    }
    return res;
}

int main()
{
    int n; cin >> n;
    int arr[n][5];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++)
            cin >> arr[i][j];
    cout << totalDistortion(arr, n);
   return 0;
}