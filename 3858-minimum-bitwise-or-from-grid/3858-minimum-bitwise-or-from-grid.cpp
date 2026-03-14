class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int mask = (1<<21)-1;
        int n = grid.size();
        int m = grid[0].size();
        for (int bit = 20; bit >= 0; bit--) {
            int cnt = 0;
            int target = mask ^ (1 << bit);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((grid[i][j] | target) == target) {
                        cnt++;
                        break;
                    }
                }
            }
            if (cnt == n){
                mask = target;
            }
        }
        return mask;
    }
};