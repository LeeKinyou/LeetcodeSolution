#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res(word.length(), 0);
            
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = s.divisibilityArray("123456789", 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}