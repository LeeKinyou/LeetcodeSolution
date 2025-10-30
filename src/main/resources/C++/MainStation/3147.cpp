#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(), -0x7f7f7f);
        dp[0] = energy[0];
        if (k >= energy.size()) {
            for (int i = 1; i < energy.size(); i++) {
                dp[i] = max(dp[i - 1], energy[i]);
            }
            return dp[energy.size() - 1];
        }i
        for (int i = 1; i < energy.size(); i++) {
            if (i <= k) {
                dp[i] = energy[i];
            } else {
                if (dp[i - k] <= 0) {
                    dp[i] = energy[i];
                } else {
                    dp[i] = dp[i - k] + energy[i];
                }
            }
        }
        for (int i = energy.size() - k + 1; i < energy.size(); i++) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        for (int i : dp) {
            cout << i << " ";
        }
        return dp[energy.size() - 1];
    }
};

int main() {

    return 0;
}