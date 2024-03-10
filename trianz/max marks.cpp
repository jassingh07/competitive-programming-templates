#include<bits/stdc++.h>
using namespace std;
int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int max_marks(int n, int arr[]){
    qsort(arr, n, sizeof(int), compare);
    int sum = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] <= arr[i - 1])
            arr[i] = arr[i - 1] + 1;
        
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int n; cin >> n; 
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    cout << max_marks(n, arr);
   return 0;
}