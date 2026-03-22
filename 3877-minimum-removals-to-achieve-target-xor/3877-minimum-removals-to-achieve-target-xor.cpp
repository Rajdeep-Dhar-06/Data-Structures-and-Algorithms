class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int LIM = 1 << 14;

        vector<vector<int>> dp(n + 1, vector<int>(LIM, -1e9));

        // base case
        for (int j = 0; j < LIM; j++) {
            if (j == target) dp[n][j] = 0;
        }

        // fill bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < LIM; j++) {
                // skip
                int ans = dp[i + 1][j];

                // take
                int take = 1 + dp[i + 1][j ^ nums[i]];

                dp[i][j] = max(ans, take);
            }
        }

        int ans = dp[0][0];
        return (ans < 0 ? -1 : n - ans);
    }
};