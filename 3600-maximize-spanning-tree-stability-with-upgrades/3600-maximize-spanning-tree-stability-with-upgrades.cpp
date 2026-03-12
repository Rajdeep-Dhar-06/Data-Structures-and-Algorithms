class Solution {
public:
    struct DSU {
        vector<int> parent, sz;
        int c;

        DSU(int n) {
            parent.resize(n);
            sz.resize(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;
            c = n;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]); // path compression
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return;

            if (sz[a] < sz[b])
                swap(a, b); // small to large

            parent[b] = a;
            sz[a] += sz[b];
            c--;
        }

        bool same(int a, int b) { return find(a) == find(b); }
    };

    bool check(int mid, int n, vector<vector<int>>& edgeList, int k, DSU dsu) {
        for (auto e : edgeList) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            if (dsu.same(u, v))
                continue;

            if (s >= mid)
                dsu.unite(u, v);
        }

        for (auto e : edgeList) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            if (dsu.same(u, v))
                continue;

            if (k > 0 && 2LL * s >= mid) {
                dsu.unite(u, v);
                k--;
            }
        }

        return dsu.c == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 1e9, ans = -1;
        vector<vector<int>> edgeList;
        DSU dsu(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            int m = e[3];

            if (m == 1) {
                hi = min(hi, s);
                if (dsu.same(u, v))
                    return -1;
                dsu.unite(u, v);
            } else {
                edgeList.push_back(e);
            }
        }
        sort(edgeList.begin(), edgeList.end(),
             [](auto& a, auto& b) { return a[2] > b[2]; });

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid, n, edgeList, k, dsu)) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans;
    }
};