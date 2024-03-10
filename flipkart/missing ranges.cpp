#include<bits/stdc++.h>
using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        auto f = [](int a, int b) {
            return a == b ? to_string(a) : to_string(a) + "->" + to_string(b);
        };
        int n = nums.size();
        vector<string> ans;
        if (n == 0) {
            ans.emplace_back(f(lower, upper));
            return ans;
        }
        if (nums[0] > lower) {
            ans.emplace_back(f(lower, nums[0] - 1));
        }
        for (int i = 1; i < n; ++i) {
            int a = nums[i - 1], b = nums[i];
            if (b - a > 1) {
                ans.emplace_back(f(a + 1, b - 1));
            }
        }
        if (nums[n - 1] < upper) {
            ans.emplace_back(f(nums[n - 1] + 1, upper));
        }
        return ans;
    }

int main()
{
    int n; cin >> n;
    vector<int> in(n); for(int i = 0; i < n; i++) cin >> in[i];
    int lower, upper; cin >> lower >> upper;
    sort(in.begin(), in.end());
    vector<string> res = findMissingRanges(in, lower, upper);
    cout << '[';
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i];
        if(i != res.size() - 1) cout << ",";
    }
    cout << ']';
   return 0;
}