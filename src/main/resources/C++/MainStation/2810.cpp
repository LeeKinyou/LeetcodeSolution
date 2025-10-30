#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'i') {
                reverse(str.begin(), str.end());
            } else {
                str += s[i];
            }
        }
        return str;
    }
};

int main() {

    return 0;
}