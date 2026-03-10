class Solution {
public:
    int M = 1e9 + 7;
    int numberOfStableArrays(int z, int o, int k) {
        vector<vector<vector<int>>> dp(
            z + 1, vector<vector<int>>(o + 1, vector<int>(2, 0)));
        for (int i = 0; i <= z; i++) {
            for (int j = 0; j <= o; j++) {
                for (int x = 0; x < 2; x++) {
                    int level = i + j;
                    if (level == 0) {
                        if (i == 0 && j == 0)
                            dp[i][j][x] = 1;
                    } else {
                        if (x == 0) {
                            int R = i - 1 >= 0 ? dp[i - 1][j][1] : 0;
                            int L = i - k - 1 >= 0 ? dp[i - k - 1][j][1] : 0;
                            dp[i][j][x] = (R - L + M) % M;
                            if (i - 1 > 0)
                                (dp[i][j][x] += dp[i - 1][j][x]) %= M;
                        } else {
                            int R = j - 1 >= 0 ? dp[i][j - 1][0] : 0;
                            int L = j - k - 1 >= 0 ? dp[i][j - k - 1][0] : 0;
                            dp[i][j][x] = (R - L + M) % M;
                            if (j - 1 > 0)
                                (dp[i][j][x] += dp[i][j - 1][x]) %= M;
                        }
                    }
                }
            }
        }

        return (dp[z][o][0] + dp[z][o][1]) % M;
    }
};