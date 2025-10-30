#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct node
    {
        int left, right;
    };
     
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<node>nodes(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            nodes[i].left = i - k;
            nodes[i].right = i + k;
        }
        sort(nodes.begin(), nodes.end(), [](node a, node b) {
            return a.left == b.left ? a.right < b.right : a.left < b.left;
        });

        map<int, int> events;
        for (const auto& n : nodes) {
            events[n.left]++;
            events[n.right + 1]--;
        }

        int current_coverage = 0;
        int max_frequency = 0;
        for (auto& [pos, delta] : events) {
            current_coverage += delta;
            max_frequency = max(max_frequency, current_coverage);
        }

        return max_frequency;
    }
};

int main() {

    return 0;
}