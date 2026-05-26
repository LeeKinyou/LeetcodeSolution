#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int ans = 0;
        for (int i = nums.size() - 1; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums[0];
    }
};

int main() {

    return 0;
}