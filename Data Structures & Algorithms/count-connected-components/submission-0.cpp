class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        // Gộp cây nhỏ vào cây lớn
        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto& edge : edges) {
            if (unite(edge[0], edge[1])) {
                components--;
            }
        }

        return components;
    }
};