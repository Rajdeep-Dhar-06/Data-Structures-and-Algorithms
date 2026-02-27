class Solution {
public:
    int minOperations(string s, int k) {
        int z = 0, n = s.size();
        for (auto ch : s) {
            z += (ch == '0');
        }

        queue<pair<int, int>> q;
        set<int> s1;
        set<int> s2;

        for (int i = 0; i <= n; i++) {
            if (i & 1)
                s1.insert(i);
            else
                s2.insert(i);
        }

        q.push({0, z});

        while (!q.empty()) {
            auto [d, z] = q.front();
            q.pop();

            if (z == 0)
                return d;

            int minF = max(0, k - n + z);
            int maxF = min(z, k);

            int z1 = z + k - 2 * maxF;
            int z2 = z + k - 2 * minF;

            set<int>& s = z1 & 1 ? s1 : s2;

            auto it = s.lower_bound(z1);
            while (it != s.end() && *it <= z2) {
                int nz = *it;
                it = s.erase(it);

                q.push({d + 1, nz});
            }
        }

        return -1;
    }
};