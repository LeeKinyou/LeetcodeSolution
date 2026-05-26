#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        // nlogn time
        int pos = -1, cnt = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            return binary;
        }
        sort(binary.begin() + pos, binary.end(), [](char a, char b) {
            return a < b;
        });
        for (int i = 0; i < binary.size(); i++) {
            cout << binary[i];
        }
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                cnt++;
            }
        }
        for (int i = pos; i < pos + cnt; i++) {
            binary[i] = '1';
        }
        return binary;

        int pos = -1, cnt = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            return binary;
        }
    //    // n time
    //     for (int i = 0; i < binary.size(); i++) {
    //         if (binary[i] == '0') {
    //             cnt++;
    //         }
    //     }
    //     list<bool>li;
    //     for (int i = 0; i < binary.size(); i++) {
    //         if (binary[i] == '0') {
    //             li.push_back(false);
    //         } else {
    //             li.push_back(true);
    //         }
    //     }
    //     int num = 0;
    //     auto it = li.begin();
    //     while (it != li.end()) {
    //         if (num < pos) {
    //             num++;
    //             it++;
    //             continue;
    //         }
    //         if (num == binary.size()) {
    //             break;
    //         }
    //         if (*it == true) {
    //             it = li.erase(it);
    //             li.push_back(true);
    //         } else {
    //             it++;
    //         }
    //         num++;
    //     }
    //     num = 0;
    //     it = li.begin();
    //     while (it != li.end()) {
    //         if (num < pos) {
    //             num++;
    //             it++;
    //             continue;
    //         }
    //         if (num == pos + cnt) {
    //             break;
    //         }
    //         *it = true;
    //         it++;
    //         num++;
    //     }
    //     string ans = "";
    //     for (auto i : li) {
    //         if (i == true) {
    //             ans += '1';
    //         } else {
    //             ans += '0';
    //         }
    //     }
    //     return ans;
    }
};

int main() {

    return 0;
}