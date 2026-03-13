class Solution {
public:
    bool check(long long mid, long long mh, vector<int>& wt) {
        for (int i = 0; i < wt.size(); i++) {
            long long c = (mid * 2LL) / wt[i];
            long long x = floor(((sqrt(1 + 4 * c)) - 1) / 2LL);
            mh -= x;
        }
        return mh <= 0;
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long limit = (mh * (mh + 1LL)) / 2;
        long long lo = 0, hi = *max_element(wt.begin(), wt.end())*limit, ans;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid, mh, wt)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};