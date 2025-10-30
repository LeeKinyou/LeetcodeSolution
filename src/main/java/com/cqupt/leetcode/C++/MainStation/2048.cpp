#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> final_number;
    vector<int> start_number = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666, 1224444};

    void get_number(vector<int> number) {
        do {
            int sum = 0;
            for (int i = 0; i < number.size(); i++) {
                // cout << number[i] << " ";
                sum = number[i] + 10 * sum;
            }
            // cout << endl;
            final_number.push_back(sum);
        } while (next_permutation(number.begin(), number.end()));
    }

    void number_to_vector(int n) {
        vector<int> number;
        while (n) {
            number.push_back(n % 10);
            n /= 10;
        }
        reverse(number.begin(), number.end());
        get_number(number);
    }

    int nextBeautifulNumber(int n) {
        for (int i = 0; i < start_number.size(); i++) {
            number_to_vector(start_number[i]);
        }
        sort(final_number.begin(), final_number.end());
        for (int i = 0; i < final_number.size(); i++) {
            if (final_number[i] > n) {
                return final_number[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    s.nextBeautifulNumber(1);
    return 0;
}