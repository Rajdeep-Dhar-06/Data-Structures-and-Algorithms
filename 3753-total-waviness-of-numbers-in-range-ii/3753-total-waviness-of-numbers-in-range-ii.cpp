class Solution {
public:
    string a, b;
    long long dp[17][2][2][11][11][2][15];

    long long rec(int i, int tlo, int thi, int l, int sl, int z, int sum) {
        if (i == b.size()) {
            return sum;
        }

        if (dp[i][tlo][thi][l][sl][z][sum] != -1) {
            return dp[i][tlo][thi][l][sl][z][sum];
        }

        long long ans = 0;
        int lo = tlo ? a[i] - '0' : 0;
        int hi = thi ? b[i] - '0' : 9;

        for (int j = lo; j <= hi; j++) {
            int ntlo = tlo && (j == lo);
            int nthi = thi && (j == hi);
            int nz = z && (j == 0); 
            int nl = l, nsl = sl, nsum = sum;

            if (!nz) {
                nsl = l;
                nl = j;
                if (sl != 10 && l != 10) {
                    if ((sl < l && l > j) || (sl > l && l < j)) {
                        nsum++;
                    }
                }
            }
            ans += rec(i + 1, ntlo, nthi, nl, nsl, nz, nsum);
        }

        return dp[i][tlo][thi][l][sl][z][sum] = ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        a = to_string(num1);
        b = to_string(num2);
        int diff = b.size() - a.size();
        string temp = "";
        while (diff--) {
            temp += "0";
        }
        a = temp + a;
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, 1, 10, 10, 1, 0);
    }
};