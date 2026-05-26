#include "utils.cpp"

using namespace std;

/**
 * @brief 给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。
 */
class Solution {
public:
    int getOneCount(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++) {
            res[i] = getOneCount(i);
        }
        return res;
    }
};

int main() {

    return 0;
}