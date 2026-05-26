#include "utils.cpp"

using namespace std;
/**
 * 思路：
 * 直接转成数字加起来再转成字符串，因为没有注意字符串太长直接爆掉了
 * 使用高精加法即可
 */


/**
 * @brief 给定两个 01 字符串 a 和 b ，计算它们的和，并以二进制字符串的形式输出。
 */
class Solution {
public:
    /**
     * @brief 把字符串二进制数字转成数组
     * @param s 二进制字符串
     * @return 倒序的数字数组
     */
    vector<int> string_to_vector(string s) {
        vector<int> res;
        for (int i = s.size() - 1; i >= 0; i--) {
            res.push_back(s[i] - '0');
        }
        return res;
    }

    /**
     * @brief 数组加法
     * @param a 数组a
     * @param b 数组b
     * @return 数组a + 数组b
     */
    vector<int> add(vector<int> a, vector<int> b) {
        vector<int> res;
        int t = 0;
        // printVector(a);
        // printVector(b);
        for (int i = 0; i < a.size() || i < b.size() || t; i++) {
            if (i < a.size()) t += a[i];
            if (i < b.size()) t += b[i];
            res.push_back(t % 2);
            t /= 2;
        }
        return res;
    }

    string vector_to_string(vector<int> res) {
        string res_str = "";
        for (int i = res.size() - 1; i >= 0; i--) res_str += to_string(res[i]);
        return res_str;
    }

    /**
     * @brief 模拟加法运算
     * 
     * @param a 01字符串
     * @param b 01字符串
     * @return string 二进制字符串
     */
    string addBinary(string a, string b) {
        vector<int> a_vec = string_to_vector(a);
        vector<int> b_vec = string_to_vector(b);
        vector<int> res = add(a_vec, b_vec);
        return vector_to_string(res);
    }
};
int main() {
    Solution s;
    cout << s.addBinary("11", "10");
    return 0;
}