#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "--X" || operations[i] == "X--") {
                X--;
            } else {
                X++;
            }
        }
        return X;
    }
};

int main() {

    return 0;
}