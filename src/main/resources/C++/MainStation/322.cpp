#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) 
            return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(coins[j] <= i){
                    if (dp[i - coins[j]] != INT_MAX) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
        }
        // for (auto i : dp) {
        //     cout << i << " ";
        // }
        if(dp[amount] == INT_MAX) 
            return -1;
        return dp[amount];
    }
};

int main() {
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    Solution ob;
    cout << ob.coinChange(arr, m) << endl;
    return 0;
}