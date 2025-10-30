#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int, int> count;
        for (int a : changed) {
            count[a]++;
        }
        vector<int> res;
        for (int a : changed) {
            if (count[a] == 0) {
                continue;
            }
            count[a]--;
            if (count[a * 2] == 0) {
                return {};
            }
            count[a * 2]--;
            res.push_back(a);
        }
        return res;
    }
};

int main() {
    vector <int> changed = {0,0,0,0};
    Solution s;
    vector <int> ans = s.findOriginalArray(changed);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}