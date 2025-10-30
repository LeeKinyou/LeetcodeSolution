#include "utils.cpp"

using namespace std;

class Solution {
public:
    int maxf(int x, int y) {
        return x > y ? x : y;
    }

    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<vector<bool>> words_bitmap(words.size(), vector<bool>(26, false));
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                words_bitmap[i][c - 'a'] = true;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                bool flag = true;
                for (int k = 0; k < 26; k++) {
                    if (words_bitmap[i][k] && words_bitmap[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = maxf(ans, words[i].size() * words[j].size());
                }

            }
        }
        return ans;
    }
};

int main() {

    return 0;
}