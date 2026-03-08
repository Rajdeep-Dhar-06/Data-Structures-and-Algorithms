class Solution {
public:
    int n;
    vector<long long> pf;
    // map<pair<int, int>, long long> mp;
    long long rec(string &s, int l, int r, int e, int f) {
        // p
        // bc
        if (r == l) {
            int ans = f;
            if (s[l-1] == '1') {
                ans = e;
            }
            return ans;
        }
        // cc
        // if (mp.find({l, r}) != mp.end())
        //     return mp[{l, r}];
        // t
        long long ans = 0;
        long long sen = (pf[r] - pf[l - 1]);
        int mid = (l + r) / 2;
        if(sen==0) ans = f;
        else ans = (r - l + 1) * sen * e;
        if((r-l+1)%2==0) ans = min(ans, rec(s, l, mid, e, f) + rec(s, mid + 1, r, e, f));
        // sr
        // mp[{l, r}] = ans;
        return ans;
    }
    long long minCost(string s, int e, int f) {
        n = s.size();
        pf.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pf[i] = pf[i - 1] + (s[i - 1] == '1' ? 1 : 0);
        }
        // mp.clear();
        return rec(s, 1, n, e, f);
    }
};