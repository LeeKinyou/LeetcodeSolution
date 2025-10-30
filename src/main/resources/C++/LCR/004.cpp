#include "utils.cpp"

using namespace std;

/**
 * @brief 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
 */
class SolutionBF {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto it : mp) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return -1;
    }
};

/*
这个题目有一个简化版的类似的题目“输入数组中除一个数字只出现一次之外其他数字都出现两次，请找出只出现一次的数字”。任何一个数字异或它自己的结果都是0。如果将数组中所有数字进行异或运算，那么最终的结果就是那个只出现一次的数字。

在这个题目中只有一个数字出现了一次，其他数字出现了3次。相同的3个数字异或的结果是数字本身，但是将数组中所有数字进行异或运算并不能消除出现3次的数字。因此，需要想其他办法。

一个整数是由32个0或1组成的。我们可以将数组中所有数字的同一位置的数位相加。如果将出现3次的数字单独拿出来，那么这些出现了3次的数字的任意第i
个数位之和都能被3整除。

因此，如果数组中所有数字的第i
个数位相加之和能被3整除，那么只出现一次的数字的第i
个数位一定是0；如果数组中所有数字的第i
个数位相加之和被3除余1，那么只出现一次的数字的第i
个数位一定是1。

这样只出现一次的任意第i
个数位可以由数组中所有数字的第i
个数位之和推算出来。当我们知道一个整数任意一位是0还是1之后，就可以知道它的数值。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bitsums(32, 0);
        for(int num : nums){
            for(int i = 0; i < 32; i++){
                bitsums[i] += (num >> (31 - i)) & 1;
            }
        }
        int result = 0;
        for(int i = 0; i < 32; i++){
            result = (result << 1) + bitsums[i] % 3;
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    for (int i = 0; i < 30000; i++) {
        int num = rand();
        nums.push_back(num);
        nums.push_back(num);
        nums.push_back(num);
    }
    nums[0] = 1903423;
    SolutionBF sbf;
    clock_t start = clock();
    cout << sbf.singleNumber(nums) << endl;
    clock_t end = clock();
    cout << "My Time used: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;
    Solution s;
    start = clock();
    cout << s.singleNumber(nums) << endl;
    end = clock();
    cout << "Solution Time used: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;
    return 0;
}