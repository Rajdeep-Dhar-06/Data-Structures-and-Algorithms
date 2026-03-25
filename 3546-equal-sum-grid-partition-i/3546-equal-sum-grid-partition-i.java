class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        long[] row = new long[m];
        long[] col = new long[n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        for(int i=1; i<m; i++){
            row[i] += row[i-1];
        }

        for(int i=1; i<n; i++){
            col[i] += col[i-1];
        }

        for (int i = 0; i < m - 1; i++) {
            if (row[m - 1] - row[i] == row[i])
                return true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (col[n - 1] - col[i] == col[i])
                return true;
        }

        return false;
    }
}
