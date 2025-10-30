#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        for (int i = 0; i < coins.size(); ++i) {
            cout << coins[i] << endl;
        }
        for (auto &i: coins) {
            i = 1;
        }
        for (int i = 0; i < coins.size(); ++i) {
            cout << coins[i] << endl;
        }
    }
};
int main() {
    Solution s;
    vector <int> coins = {1, 2, 5};
    cout << s.change(5, coins) << endl;
    return 0;
}