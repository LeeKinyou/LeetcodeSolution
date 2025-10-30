#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void init(int n) {
        G.resize(n);
        ans.resize(n);
        rudu.resize(n, 0);
        vis.resize(n, false);
        res.resize(n);  
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        init(n);
        for (int i = 0; i < edges.size(); i++) {
            G[edges[i][0]].push_back(edges[i][1]);
            rudu[edges[i][1]]++;
        }
        int cnt = 0;
        // ans[0].insert(10);
        // ans[0].insert(12);
        // for (int i: ans[0]) {
        //     cout << i << " ";
        // }
        while (cnt < n) {
            for (int i = 0; i < n; i++) {
                if (vis[i])
                    continue;
                if (rudu[i] == 0) {
                    for (int j = 0; j < G[i].size(); j++) {
                        ans[G[i][j]].insert(i);
                        for (auto k: ans[i]) {
                            ans[G[i][j]].insert(k);
                        }
                        rudu[G[i][j]]--;
                    }
                    vis[i] = true;
                    cnt++;
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j: ans[i]) {
        //         cout << j << " ";
        //     }cout << endl;
        // }
        
        for (int i = 0; i < n; i++) {
            res[i].assign(ans[i].begin(), ans[i].end());
        }
        for (int i = 0; i < n; i++) {
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
    
private:
    vector<vector<int>> G;
    vector<vector<int>> res;
    vector<set<int>> ans;
    vector<int>rudu;
    vector<bool>vis;
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    s.getAncestors(5, edges);

    return 0;
}