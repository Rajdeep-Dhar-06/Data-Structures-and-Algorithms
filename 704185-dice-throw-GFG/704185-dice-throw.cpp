class Solution {
  public:
    vector<vector<int>> dp;
    int rec(int i, int m, int n, int x){
        if(i==n){
            if(x==0) return 1;
            else return 0;
        }
        if(dp[i][x]!=-1) return dp[i][x];
        int ans = 0;
        for(int j=1; j<=m; j++){
            if(x-j >= 0)
            ans += rec(i+1, m, n, x-j);
        }
        return dp[i][x]=ans;
    }
    int noOfWays(int m, int n, int x) {
        dp.resize(n+1, vector<int>(x+1, -1));
        return rec(0,m,n,x);
    }
};