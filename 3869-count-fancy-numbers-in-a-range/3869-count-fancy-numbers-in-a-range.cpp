class Solution {
public:
    long long dp[16][2][11][9 * 15][4][2][2];
    string a, b;
    bool check(int n) {
        int x = n;
        int next1 = 1e9;
        int next2 = -1;
        int flag1 = true;
        int flag2 = true;
        while (x > 0) {
            int d = x % 10;
            if (d >= next1)
                flag1 = false;
            x /= 10;
            next1 = d;
        }
        x = n;
        while (x > 0) {
            int d = x % 10;
            if (d <= next2)
                flag2 = false;
            x /= 10;
            next2 = d;
        }
        return (flag1 || flag2);
    }
    long long rec(int i, int st, int prev, int sum, int f, int tlo, int thi) {
        // p
        // bc
        if (i == b.size()) {
            if (f == 0 || f == 1 || f == 2)
                return 1;
            else if (check(sum))
                return 1;
            return 0;
        }
        // cc
        if (dp[i][st][prev][sum][f][tlo][thi] != -1)
            return dp[i][st][prev][sum][f][tlo][thi];
        // t
        long long ans = 0;
        int lo = 0, hi = 9;
        if (tlo == 1)
            lo = a[i] - '0';
        if (thi == 1)
            hi = b[i] - '0';

        for (int j = lo; j <= hi; j++) {
            int ntlo = tlo && (j == a[i] - '0');
            int nthi = thi && (j == b[i] - '0');
            int nst = (st == 0 && j == 0) ? 0 : 1;
            if (st == 1) {
                int nf = 3;
                if (f == 0) {
                    if (j > prev)
                        nf = 1;
                    else if (j < prev)
                        nf = 2;
                } else if (f == 1) {
                    if (j > prev)
                        nf = 1;
                } else if (f == 2) {
                    if (j < prev)
                        nf = 2;
                }
                ans += rec(i + 1, 1, j, sum + j, nf, ntlo, nthi);
            } else {
                if (j == 0) {
                    ans += rec(i + 1, 0, 0, 0, 0, ntlo, nthi);
                } else {
                    ans += rec(i + 1, 1, j, j, 0, ntlo, nthi);
                }
            }
        }
        // sr
        return dp[i][st][prev][sum][f][tlo][thi] = ans;
    }
    long long countFancy(long long l, long long r) {
        a = to_string(l);
        b = to_string(r);
        int len = b.length() - a.length();
        string temp = "";
        while (len--)
            temp += "0";
        a = temp + a;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 10, 0, 0, 1, 1);
    }
};