#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 2; i < nums.size(); ++i) {
            int a = nums[i - 2], b = nums[i - 1], c = nums[i];
            if (a + b > c) res = max(res, a + b + c);
        }
        return res;
    }
};
int main() {

    return 0;
}