class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> X(n, vector<int>(m, 0));
        vector<vector<int>> Y(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = grid[i][j];
                if (i > 0) {
                    X[i][j] += X[i - 1][j];
                    Y[i][j] += Y[i - 1][j];
                }
                if (j > 0) {
                    X[i][j] += X[i][j - 1];
                    Y[i][j] += Y[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    X[i][j] -= X[i - 1][j - 1];
                    Y[i][j] -= Y[i - 1][j - 1];
                }

                if (ch == 'X')
                    X[i][j]++;
                else if (ch == 'Y')
                    Y[i][j]++;

                if (X[i][j] == Y[i][j] && X[i][j] > 0)
                    ans++;
            }
        }
        return ans;
    }
};