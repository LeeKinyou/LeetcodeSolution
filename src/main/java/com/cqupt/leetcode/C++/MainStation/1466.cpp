#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
class Solution {
public:
    void add(int u, int v, int w) {
        G[u].push_back(v);
        W[u].push_back(w);
    }

    void resize(int n) {
        G.resize(n);
        W.resize(n);
        vis.resize(n, 0);
    }

    void dfs(int u) {
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); i++) {
            if (vis[G[u][i]])
                continue;
            ans += W[u][i];
            // cout << u << " " << G[u][i] << " " << ans << endl;
            dfs(G[u][i]);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        resize(n);
        for (int i = 0; i < connections.size(); i++) {
            add(connections[i][0], connections[i][1], 1);
            add(connections[i][1], connections[i][0], 0);
        }
        dfs(0);
        return ans;
    }
private:
    int ans = 0;
    vector<int>vis;
    vector<vector<int>>G;
    vector<vector<int>>W;
};
int main() {
    Solution s;
    int n = 6;
    vector<vector<int>>connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << s.minReorder(n, connections) << endl;
    return 0;
}