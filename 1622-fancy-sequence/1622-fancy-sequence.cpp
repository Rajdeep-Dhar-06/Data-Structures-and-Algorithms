class Fancy {
public:
    long long MOD;
    long long sum;
    long long mul;
    vector<int> v;
    Fancy() {
        sum = 0;
        mul = 1;
        MOD = 1e9 + 7;
        v.clear();
    }
    long long modpow(long long a, long long b, long long mod) {
        int res = 1;
        a %= mod;

        while (b) {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    //(x-sum)/mul
    void append(int val) {
        long long invMul = modpow(mul, MOD-2, MOD);
        int x = ((val-sum+MOD)*invMul)%MOD;
        v.push_back(x);
    }

    void addAll(int inc) {
        (sum += 1LL*inc)%=MOD;
    }

    void multAll(int m) {
        (mul *= 1LL*m)%=MOD;
        (sum *= 1LL*m)%=MOD;
    }

    //(x*mul)+sum
    int getIndex(int idx) {
        int n = v.size();
        if(idx<0 || idx>=n) return -1;
        int x = ((v[idx]*mul)%MOD+sum)%MOD;
        return x;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */