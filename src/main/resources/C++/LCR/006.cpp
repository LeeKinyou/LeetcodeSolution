#include "utils.cpp"

using namespace std;

class Solution {
public:
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