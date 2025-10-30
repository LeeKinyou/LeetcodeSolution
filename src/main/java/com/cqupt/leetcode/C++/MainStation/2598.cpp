#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        value = abs(value);
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i] % value]++;
        }
        for (int i = 0; i < value; i++) {
            if (m[i] == 0) {
                return i;
            }
        }
        return value;
    }
};

int main() {
    return 0;
}