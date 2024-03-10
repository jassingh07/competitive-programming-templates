#include <bits/stdc++.h>
using namespace std;
 
int MaxIndexDiff(int* v, int n){
    vector<long long int> mEnd(n + 1, INT_MIN);
 
    for (int i = n - 1; i >= 0; i--) {
        mEnd[i] = max(mEnd[i + 1], v[i]);
    }
 
    int result = 0;
 
    for (int i = 0; i < n; i++) {
        int low = i + 1, high = n - 1, ans = i;
 
        while (low <= high) {
            int mid = (low + high) / 2;
 
            if (v[i] <= mEnd[mid]) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        result = max(result, ans - i);
    }
    return result;
}

int main()
{
    int n; cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << MaxIndexDiff(arr, n) << endl;
}