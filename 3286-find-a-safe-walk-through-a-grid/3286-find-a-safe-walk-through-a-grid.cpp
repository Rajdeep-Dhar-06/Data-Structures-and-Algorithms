class Solution {
public:
    vector<vector<int>> dist;
    vector<vector<int>> vis;
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool isValid(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
    int bfs(int i, int j, vector<vector<int>>& g) {
        deque<pair<int, pair<int, int>>> dq;
        dist[i][j] = g[i][j]==0 ? 0 : 1;
        dq.push_back({dist[i][j], {i, j}});

        while (!dq.empty()) {
            auto [d, u] = dq.front();
            auto [x, y] = u;
            dq.pop_front();

            if(vis[x][y]) continue;
            vis[x][y] = 1;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny) && !vis[nx][ny]) {
                    if (g[nx][ny] == 1) {
                        dist[nx][ny] = min(dist[nx][ny], 1 + d);
                        dq.push_back({dist[nx][ny], {nx, ny}});
                    } else {
                        dist[nx][ny] = min(dist[nx][ny], d);
                        dq.push_front({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();
        dist.resize(n, vector<int>(m, 1e9));
        vis.resize(n, vector<int>(m, 0));
        return bfs(0, 0, grid) < health;
    }
};