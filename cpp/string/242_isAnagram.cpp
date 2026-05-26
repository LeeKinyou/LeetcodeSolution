
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26, 0), v2(26, 0);
        for (int i = 0; i < s.size(); i++) {
            v1[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            v2[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    cout << "Hello World!" << endl;
    return 0;
}