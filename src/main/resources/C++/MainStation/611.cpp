#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int min_num = abs(nums[i] - nums[j]) + 1;
                int max_num = nums[i] + nums[j] - 1;
                int pos_min = lower_bound(nums.begin() + j + 1, nums.end(), min_num) - nums.begin();
                int pos_max = upper_bound(nums.begin() + j + 1, nums.end(), max_num) - nums.begin();
                if (pos_min >= pos_max) {
                    continue;
                }
                // cout << pos_min << " " << pos_max << endl;
                ans += pos_max - pos_min;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0,0};
    cout << s.triangleNumber(nums) << endl;
    return 0;
}