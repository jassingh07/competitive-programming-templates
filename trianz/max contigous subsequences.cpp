#include<bits/stdc++.h>
using namespace std;

int FindContigousSeq(int n, int arr[]){
    int res = 0, cur = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) cur += arr[i];
        else {
            res = max(res, cur);
            cur = 0;
        }
        res = max(res, cur);
    }
    return res;
}
int main()
{
    int n; cin >> n; 
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    cout << FindContigousSeq(n, arr);
   return 0;
}