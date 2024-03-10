#include<bits/stdc++.h>
using namespace std;


int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

class Sparse{
    vector<vector<int>> st;
    int K;
    public:
    Sparse(vector<int>& arr){
        int n = arr.size();
        K = log2_floor(n);
        st.resize(K + 1, vector<int>(n));
        std::copy(arr.begin(), arr.end(), st[0].begin());

        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = st[i - 1][j] |st[i - 1][j + (1 << (i - 1))];
    }
    int query(int L, int R){
        int sum = 0;
        for (int i = K; i >= 0; i--) {
            if ((1 << i) <= R - L + 1) {
                sum |= st[i][L];
                L += 1 << i;
            }
        }
        return sum;
    }
};

int countSubarraysWithBitwiseOR(vector<int>& nums, int x) {
    int n = nums.size();
    int count = 0;
    Sparse st(nums);

    for (int i = 0; i < n; i++) {
        int left = i;
        int right = n - 1;
        int le = -1, re = -1;
        // Binary search for the rightmost index 'right' such that OR of subarray [i, right] is less than x
        while (left <= right) {
            int mid = (left + right) / 2;
            int subarrayOR = st.query(i, mid);

            if (subarrayOR == x) {
                right = mid - 1;
                le = mid;
                re = mid;
            } else if(subarrayOR > x){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        left = i, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int subarrayOR = st.query(i, mid);

            if (subarrayOR == x) {
                left = mid + 1;
                re = mid;
            } else if(subarrayOR > x){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        // cout << i << " " << le << " " << re << endl;
        if(re != -1) count += re - le + 1; // All subarrays [i, left], [i, left+1], ..., [i, n-1] have OR equal to x
    }

    return count;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < Q; ++i) {
        int query;
        cin >> query;
        cout << countSubarraysWithBitwiseOR(nums, query) << endl;
    }

    return 0;
}
