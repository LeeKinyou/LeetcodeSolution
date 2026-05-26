#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        // 计算邻接矩阵的4次幂
        vector<vector<int>> result = matrix;
        
        // 矩阵乘法函数
        auto multiply = [&](const vector<vector<int>>& A, const vector<vector<int>>& B) {
            vector<vector<int>> C(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            return C;
        };
        
        // 计算matrix^4
        vector<vector<int>> temp = matrix;
        for (int power = 1; power < 4; power++) {
            temp = multiply(temp, matrix);
        }
        
        // 返回所有元素之和，即长度为4的通路总数
         int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += temp[i][i];
        }
        
        return sum;
    }
};
class Solution1 {
public:
    int getSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        // 计算邻接矩阵的3次幂
        vector<vector<int>> result = matrix;
        
        // 矩阵乘法函数
        auto multiply = [&](const vector<vector<int>>& A, const vector<vector<int>>& B) {
            vector<vector<int>> C(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            return C;
        };
        
        // 计算matrix^3
        vector<vector<int>> temp = matrix;
        for (int power = 1; power < 3; power++) {
            temp = multiply(temp, matrix);
        }
        
        // 返回从0号点出发长度为3的回路数
        return temp[0][0];
    }
};

class Solution2 {
public:
    int getSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        
        // 矩阵乘法函数
        auto multiply = [&](const vector<vector<int>>& A, const vector<vector<int>>& B) {
            vector<vector<int>> C(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            return C;
        };
        
        // 创建单位矩阵
        vector<vector<int>> identity(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            identity[i][i] = 1;
        }
        
        // 计算长度小于等于4的通路总数
        int totalSum = 0;
        vector<vector<int>> currentPower = identity; // 从单位矩阵开始
        
        // 计算1次幂到4次幂并累加对角线元素
        for (int power = 1; power <= 4; power++) {
            currentPower = multiply(currentPower, matrix); // 计算下一个幂次
            
            // 累加当前幂次的对角线元素（回路数）
            for (int i = 0; i < n; i++) {
                totalSum += currentPower[i][i];
            }
        }
        
        return totalSum;
    }
};
int main() {
    Solution2 sol;
    vector<vector<int>> adjacencyMatrix = {
        {1, 2, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}
    };
    
    cout << sol.getSum(adjacencyMatrix) << endl;
    
    return 0;
}