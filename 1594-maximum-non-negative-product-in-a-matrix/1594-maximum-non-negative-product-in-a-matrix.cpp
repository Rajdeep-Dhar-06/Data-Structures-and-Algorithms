class Solution {
public:
    // dp1[i][j] = min product ending at (i,j)
    // dp2[i][j] = max product ending at (i,j)
    int maxProductPath(vector<vector<int>>& g) {
    #define int long long
        int n = g.size();
        int m = g[0].size();
        int MOD = 1e9 + 7;
        vector<vector<int>> dp1(n, vector<int>(m, 2e9));
        vector<vector<int>> dp2(n, vector<int>(m, -2e9));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp1[i][j] = g[i][j];
                    dp2[i][j] = g[i][j];
                } else {
                    if (g[i][j] >= 0) {
                        int U1 = i > 0 ? dp1[i - 1][j] : 2e9;
                        int L1 = j > 0 ? dp1[i][j - 1] : 2e9;
                        (dp1[i][j] = g[i][j] * min(U1, L1)) ;
                        int U2 = i > 0 ? dp2[i - 1][j] : -2e9;
                        int L2 = j > 0 ? dp2[i][j - 1] : -2e9;
                        (dp2[i][j] = g[i][j] * max(U2, L2));
                    } else {
                        int U1 = i > 0 ? dp2[i - 1][j] : -2e9;
                        int L1 = j > 0 ? dp2[i][j - 1] : -2e9;
                        (dp1[i][j] = g[i][j] * max(U1, L1)) ;
                        int U2 = i > 0 ? dp1[i - 1][j] : 2e9;
                        int L2 = j > 0 ? dp1[i][j - 1] : 2e9;
                        (dp2[i][j] = g[i][j] * min(U2, L2)) ;
                    }
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << dp1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << dp2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        #undef int long long
        return dp2[n - 1][m - 1] < 0 ? -1 : dp2[n - 1][m - 1] % MOD;
    }
};