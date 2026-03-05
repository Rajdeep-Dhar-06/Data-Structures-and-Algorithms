class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
#define int long long
        vector<int> degree(n + 1, 0);
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }
        for (auto e : edges) {
            dist[e[0]][e[1]] = 1;
            dist[e[1]][e[0]] = 1;
            degree[e[0]]++;
            degree[e[1]]++;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (dist[i][j] + dist[j][k] + dist[k][i] == 3)
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
#undef int
};