#include "utils.cpp"

using namespace std;

class ThreeSum {
public:
    int first;
    int second;
    int third;
    ThreeSum(int first, int second, int third) {
        this->first = first;
        this->second = second;
        this->third = third;
    }
    bool operator==(const ThreeSum &ts) const {
        return first == ts.first && second == ts.second && third == ts.third;
    }

    bool operator<(const ThreeSum &ts) const {
        if (first != ts.first) return first < ts.first;
        if (second != ts.second) return second < ts.second;
        return third < ts.third;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<ThreeSum>s;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            int target = -nums[i];
            vector<int> two = twoSum(nums, target);
            if (two.size() > 0) {
                if (i < two[0] && i < two[1]) {
                    ThreeSum ts(i, two[0], two[1]);
                    if (s.find(ts) == s.end()) {
                        s.insert(ts);
                        res.push_back({nums[i], nums[two[0]], nums[two[1]]});
                    }
                }
            }
        }
        return res;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int num = target - numbers[i];
            int pos = lower_bound(numbers.begin() + i + 1, numbers.end(), num) - numbers.begin();
            if (pos < numbers.size() && numbers[pos] == num) {
                return {i, pos};
            }
        }
        return {};
    }
};

int main() {

    return 0;
}