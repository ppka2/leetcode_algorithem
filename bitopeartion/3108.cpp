// AND will be smaller ,so the passing every node is optional. 
class Solution {
    vector<int> fa, and_;

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        and_.resize(n, -1);
        for (auto &e: edges) {
            int x = find(e[0]);
            int y = find(e[1]);
            and_[y] &= e[2];
            if (x != y) {
                and_[y] &= and_[x];
                fa[x] = y;
            }
        }

        vector<int> ans;
        ans.reserve(query.size()); // 预分配空间
        for (auto &q: query) {
            int s = q[0], t = q[1];
            ans.push_back(find(s) != find(t) ? -1 : and_[find(s)]);
        }
        return ans;
    }
};
