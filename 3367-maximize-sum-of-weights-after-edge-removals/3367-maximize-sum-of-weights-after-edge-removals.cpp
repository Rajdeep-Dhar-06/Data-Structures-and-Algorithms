#define F first
#define S second
class Solution {
public:
    // dp[u][0] = not connected with parent
    // dp[u][1] = connected with parent
    vector<vector<long long>> dp;
    vector<vector<pair<int, int>>> g;
    void dfs(int u, int p, int w, int k) {
        dp[u][0] = 0;
        dp[u][1] = 0;
        int child = 0;
        for (auto& [v, w] : g[u]) {
            if (v == p)
                continue;
            dfs(v, u, w, k);
            child++;
        }
        if (child != 0) {
            long long nt = 0;
            vector<long long> delta;
            for (auto& [v, w] : g[u]) {
                if (v == p)
                    continue;
                nt += dp[v][0];
                delta.push_back(dp[v][1]+w-dp[v][0]);
            }
            sort(delta.begin(), delta.end());
            k--;
            dp[u][1] = nt;
            while(!delta.empty() && k>0){
                long long t = delta.back();
                delta.pop_back();
                k--;
                dp[u][1] = max(dp[u][1], dp[u][1]+t);
            }
            k++;
            dp[u][0] = dp[u][1];
            while(!delta.empty() && k>0){
                long long t = delta.back();
                delta.pop_back();
                k--;
                dp[u][0] = max(dp[u][0], dp[u][0]+t);
            }
        }
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        g.resize(n, {});
        dp.resize(n, vector<long long>(2));
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(0, -1, 0, k);
        return max(dp[0][0], dp[0][1]);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna