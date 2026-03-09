class Solution {
public:
    int n, l;
    int MOD = 1e9 + 7;
    int dp[2][201][201][201];
    int rec(int i, int z, int o, int c, int x) {
        if (z < 0 || o < 0 || c > l) return 0;

        if (i == n)
            return (z == 0 && o == 0);

        if (dp[x][z][o][c] != -1)
            return dp[x][z][o][c];

        int ans = 0;

        if (x == 0) {
            ans = (ans + rec(i + 1, z - 1, o, c + 1, 0)) % MOD;
            ans = (ans + rec(i + 1, z, o - 1, 1, 1)) % MOD;
        } 
        else {
            ans = (ans + rec(i + 1, z, o - 1, c + 1, 1)) % MOD;
            ans = (ans + rec(i + 1, z - 1, o, 1, 0)) % MOD;
        }

        return dp[x][z][o][c] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        n = zero + one;
        l = limit;
        memset(dp, -1, sizeof(dp));
        return rec(0, zero, one, 0, 0);
    }
};