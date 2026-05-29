class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        int reachable = 0;

        for(int i = 1; i < n; i++) {

            // add new index entering window
            if(i - minJump >= 0 && dp[i - minJump]) {
                reachable++;
            }

            // remove old index leaving window
            if(i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                reachable--;
            }

            dp[i] = (reachable > 0 && s[i] == '0');
        }

        return dp[n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna