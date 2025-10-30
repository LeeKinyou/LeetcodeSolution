#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>vis(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            vis[edges[i][1]] = 1;
        }
        int ans = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                ans = i;
                cnt++;
            }
        }
        if (cnt > 1) return -1;
        return ans;
    }
};

int main() {

    return 0;
}