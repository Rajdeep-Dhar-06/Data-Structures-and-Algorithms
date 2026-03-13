class Solution {
public:
    vector<int> dp;
    void LIS1(vector<vector<int>>& c, int k) {
        int n = c.size();
        vector<int> v;
        for (int i = 0; i < k; i++) {
            int x = c[i][0];
            int y = c[i][1];
            if (x == c[k][0] || y >= c[k][1])
                continue;
            if (v.empty() || v.back() < y) {
                v.push_back(y);
            } else {
                auto it = lower_bound(v.begin(), v.end(), y);
                *it = y;
            }
            dp[i] = v.size();
        }
    }

    void LIS2(vector<vector<int>>& c, int k) {
        int n = c.size();
        vector<int> v;
        for (int i = k + 1; i < n; i++) {
            int x = c[i][0];
            int y = c[i][1];
            if (x == c[k][0] || y <= c[k][1])
                continue;
            if (v.empty() || v.back() < y) {
                v.push_back(y);
            } else {
                auto it = lower_bound(v.begin(), v.end(), y);
                *it = y;
            }
            dp[i] = v.size();
        }
    }

    int maxPathLength(vector<vector<int>>& c, int k) {
        auto x = c[k];
        sort(c.begin(), c.end(), [](auto a, auto b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int n = c.size();
        for (int i = 0; i < n; i++) {
            if (c[i][0] == x[0] && c[i][1] == x[1]) {
                k = i;
                break;
            }
        }
        dp.assign(n, 0);
        LIS1(c, k);
        LIS2(c, k);
        int mx1 = 0;
        int mx2 = 0;
        for (int i = 0; i < k; i++) {
            mx1 = max(mx1, dp[i]);
            // cout << c[i][0] << " " << c[i][1] << " " << dp[i] << endl;
        }
        for (int i = k + 1; i < n; i++) {
            mx2 = max(mx2, dp[i]);
            // cout << c[i][0] << " " << c[i][1] << " " << dp[i] << endl;
        }
        return mx1 + mx2 + 1;
    }
};