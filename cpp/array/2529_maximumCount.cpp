#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int zheng = 0, fu = 0;
        for (auto i: nums) {
            if (i > 0) zheng++;
            else if (i < 0) fu = max(fu, i);
        }
        return max(zheng, fu);
    }
};
int main() {
    return 0;
}