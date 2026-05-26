#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string tmp = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int num = (s[i] - '0' + s[i + 1] - '0') % 10;
                tmp += to_string(num);
            }
            s = tmp;
        }
        if (s[0] == s[1])
            return true;
        else 
            return false;
    }
};

int main() {

    return 0;
}