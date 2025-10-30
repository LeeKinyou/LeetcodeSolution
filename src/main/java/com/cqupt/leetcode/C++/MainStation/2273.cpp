#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<bool>flag(words.size(), true);
        vector<map<char, int>>words_map(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                words_map[i][words[i][j]]++;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            if (!flag[i])
                continue;
            for (int j = i + 1; j < words.size(); j++) {
                if (words_map[i] == words_map[j]) {
                    flag[j] = false;
                } else {
                    break;
                }
            }
        }
        vector<string>ans;
        for (int i = 0; i < words.size(); i++) {
            if (flag[i])
                ans.push_back(words[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string>words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string>ans = s.removeAnagrams(words);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}