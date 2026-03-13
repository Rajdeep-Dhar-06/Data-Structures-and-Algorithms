class Solution {
public:
    bool check(long long mid, int mh, vector<int>& wt){
        long long h = 0;
        for(int i=0; i<wt.size(); i++){
            int time = wt[i];
            long long c = (mid*2LL)/time;
            long long x = floor(((sqrt(1+4*c))-1)/2);
            h += x;
        }
        return mh-h <= 0;
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long lo = 0, hi = 1e18, ans;
        while(lo <= hi){
            long long mid = (lo+hi)/2;
            if(check(mid, mh, wt)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};