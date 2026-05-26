#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        vector<int> vis(grid.size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (i != j && grid[i][j] == 1) {
                    vis[j] = 1;
                }
            }
        }
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0) {
                return i;
            }
        }
    }
};
int main() {

    return 0;
}

