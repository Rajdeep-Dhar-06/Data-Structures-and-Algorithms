class Solution {
public:
    // dp[i][j] = # of elements from [i...n] such that XOR is j
    vector<int> nums;
    int n, t;
    vector<vector<int>> dp;
    int rec(int i, int j) {
        // p
        // bc
        if (i == n) {
            if (j == t)
                return 0;
            else
                return -1e6;
        }
        // cc
        if (dp[i][j] != -1e9)
            return dp[i][j];
        // t
        int ans = max(rec(i + 1, j), 1 + rec(i + 1, j ^ nums[i]));
        // sr
        return dp[i][j] = ans;
    }
    int minRemovals(vector<int>& arr, int target) {
        nums = arr;
        t = target;
        n = nums.size();
        int lim = (1 << 15);
        dp.resize(n, vector<int>(lim, -1e9));
        int ans = rec(0, 0);
        return ans < 0 ? -1 : (n - ans);
    }
};