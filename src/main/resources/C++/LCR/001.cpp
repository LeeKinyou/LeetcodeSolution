#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 思路：
 * 二分查找res使得res * b == a, 其中乘法使用类似快速幂的快速加实现
 */
class Solution {
public:
    /**
     * @brief 给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%'
     * @param a 被除数
     * @param b 除数
     * @return 商
     */
    int divide(int a, int b) {
        // 考虑被除数为最小值的情况
        if (a == INT_MIN) {
            if (b == 1) {
                return INT_MIN;
            }
            if (b == -1) {
                return INT_MAX;
            }
        }
        // 考虑除数为最小值的情况
        if (b == INT_MIN) {
            return a == INT_MIN ? 1 : 0;
        }
        // 考虑被除数为 0 的情况
        if (a == 0) {
            return 0;
        }
        
        // 一般情况，使用类二分查找
        // 将所有的正数取相反数，这样就只需要考虑一种情况
        bool rev = false;
        if (a > 0) {
            a = -a;
            rev = !rev;
        }
        if (b > 0) {
            b = -b;
            rev = !rev;
        }

        vector<int> candidates = {b};
        // 注意溢出
        while (candidates.back() >= a - candidates.back()) {
            candidates.push_back(candidates.back() + candidates.back());
        }
        int ans = 0;
        for (int i = candidates.size() - 1; i >= 0; --i) {
            if (candidates[i] >= a) {
                ans += (1 << i);
                a -= candidates[i];
            }
        }

        return rev ? -ans : ans;
    }
};


int main() {
    Solution s;
    printf("%d\n", s.divide(-2147483648, -1));
    return 0;
}