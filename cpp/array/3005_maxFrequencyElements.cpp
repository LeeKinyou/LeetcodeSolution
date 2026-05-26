#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> number_to_freq;
        vector<int> freq_to_cnt;
        for (int i = 0; i < nums.size(); i++) {
            number_to_freq[nums[i]]++;
        }
        for (auto& [num, freq] : number_to_freq) {
            freq_to_cnt.push_back(freq);
        }
        sort(freq_to_cnt.begin(), freq_to_cnt.end(), greater<int>());
        int ans = 0, num = freq_to_cnt[0];
        for (int i = 0; i < freq_to_cnt.size(); i++) {
            if (num > freq_to_cnt[i]) {
                break;
            }
            ans += freq_to_cnt[i];
        }
        return ans;
    }
};

int main() {
    return 0;
}