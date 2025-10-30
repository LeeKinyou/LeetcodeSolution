#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> cnt(nums.begin(), nums.end());
        vector<int> sortedUniqueNums(cnt.begin(), cnt.end());
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        int res = n, j = 0;
        for (int i = 0; i < sortedUniqueNums.size(); i++) {
            int right = sortedUniqueNums[i] + n - 1;
            while (j < sortedUniqueNums.size() && sortedUniqueNums[j] <= right) {
                res = min(res, n - (j - i + 1));
                j++;
            }
        }            
        return res;
    }
};

int main() {
    Solution s;
    vector<int>nums = {1, 5, 2, 4, 1};
    s.minOperations(nums);
    return 0;
}
