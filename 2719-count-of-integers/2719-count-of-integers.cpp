class Solution {
public:
    int mx, mn;
    string n1, n2;
    int MOD = 1000000007;
    int dp[23][2][2][22*9];
    int rec(int i, int tlo, int thi, int sum, int n){
        if(i==n){
            return (sum >= mn && sum <= mx);
        }
        if(dp[i][tlo][thi][sum] != -1)
            return dp[i][tlo][thi][sum];
        int ans = 0;
        int lo = 0, hi = 9;
        if(tlo) lo = n1[i]-'0'; 
        if(thi) hi = n2[i]-'0';

        for(int j=lo; j<=hi; j++){
            int ntlo = tlo && j==lo;
            int nthi = thi && j==hi;
            (ans += rec(i+1, ntlo, nthi, sum+j, n))%=MOD;
        }

        return dp[i][tlo][thi][sum]=ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int len = num2.size()-num1.size();
        string temp = "";
        while(len--) temp+="0";
        num1 = temp+num1;
        n1 = num1;
        n2 = num2;
        mn = min_sum;
        mx = max_sum;
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, 1, 0, num2.size());
    }
};