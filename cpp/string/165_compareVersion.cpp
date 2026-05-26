#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long getNum(string version) {
        long long num = 0;
        for (int i = 0; i < version.size(); i++) {
            if (version[i] >= '0' && version[i] <= '9') {
                num = num * 10 + version[i] - '0';
            } else {
                break;
            }
        }
        return num;

    }
    int getNumList(string version, vector<long long> &v) { 
        while (version.size() > 0) {
            if (version.find('.') == -1) {
                long long num = getNum(version);
                v.push_back(num);
                break;

            }
            int i = version.find('.');
            long long num = getNum(version.substr(0, i));
            v.push_back(num);
            version = version.substr(i + 1);
        }
        return v.size();
    }

    int compareVersion(string version1, string version2) {
        vector<long long>v1, v2;
        int num1 = getNumList(version1, v1);
        int num2 = getNumList(version2, v2);
        if (num1 > num2) {
            for (int i = 0; i < num2; i++) {
                if (v1[i] > v2[i]) {
                    return 1;
                } else if (v1[i] < v2[i]) {
                    return -1;
                } 
            }
            for (int i = num2; i < num1; i++) {
                if (v1[i] != 0) {
                    return 1;
                }
            }
            return 0;
        } else if (num1 < num2) {
            for (int i = 0; i < num1; i++) {
                if (v1[i] > v2[i]) {
                    return 1;
                } else if (v1[i] < v2[i]) {
                    return -1;
                } 
            }
            for (int i = num1; i < num2; i++) {
                if (v2[i] != 0) {
                    return -1;
                }
            }
            return 0;
        } else {
            for (int i = 0; i < num1; i++) {
                if (v1[i] > v2[i]) {
                    return 1;
                } else if (v1[i] < v2[i]) {
                    return -1;
                } 
            }
            return 0;
        }
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.2147483647", "1.2147483647");
    return 0;
}