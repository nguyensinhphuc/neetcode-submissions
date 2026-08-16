class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        // Hai đỉnh đã cùng một tập
        // => thêm cạnh này sẽ tạo chu trình
        if (a == b)
            return false;

        if (rank_[a] < rank_[b])
            swap(a, b);

        parent[b] = a;

        if (rank_[a] == rank_[b])
            rank_[a]++;

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // Cây n đỉnh luôn có đúng n - 1 cạnh
        if (edges.size() != n - 1)
            return false;

        parent.resize(n);
        rank_.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Nếu tạo chu trình
            if (!unite(u, v))
                return false;
        }

        return true;
    }
};