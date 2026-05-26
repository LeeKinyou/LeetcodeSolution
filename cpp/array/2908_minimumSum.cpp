#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = INT_MAX;
        for (int j = 0; j < nums.size(); j++) {
            for (int i = 0; i < j; i++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] < nums[j] && nums[k] < nums[j]) {
                        ans = min(ans, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    } 
};

int main() {

    return 0;
}