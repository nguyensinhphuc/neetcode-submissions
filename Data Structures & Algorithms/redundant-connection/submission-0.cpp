class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        // Đã cùng một tập
        if (rootA == rootB) {
            return false;
        }

        parent[rootA] = rootB;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // Ban đầu mỗi node là một tập riêng
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Nếu không thể union => tạo chu trình
            if (!unite(u, v)) {
                return edge;
            }
        }

        return {};
    }
};