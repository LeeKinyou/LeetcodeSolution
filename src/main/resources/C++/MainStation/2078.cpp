#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for (int i = 0; i < colors.size(); i++) {
            for (int j = i + 1; j < colors.size(); j++) {
                if (colors[i] != colors[j]) {
                    ans = max(ans, abs(i - j));
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> colors = {1,1,1,3,1};
    cout << s.maxDistance(colors);
    return 0;
}