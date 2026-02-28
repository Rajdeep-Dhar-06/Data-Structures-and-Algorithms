class Solution {
public:
    int mod = 1000000007;
    long long modPow(long long a, long long b, long long mod) {
        long long result = 1;
        a %= mod;

        while (b > 0) {
            if (b & 1)
                result = (result * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return result;
    }
    int concatenatedBinary(int n) {
        int ans = 0;
        int pow = 0;
        for (int i = n; i >= 1; i--) {
            int x = i;
            while (x > 0) {
                (ans += (modPow(2, pow, mod) * (x % 2)) % mod) %= mod;
                x /= 2;
                pow++;
            }
        }
        return ans;
    }
};