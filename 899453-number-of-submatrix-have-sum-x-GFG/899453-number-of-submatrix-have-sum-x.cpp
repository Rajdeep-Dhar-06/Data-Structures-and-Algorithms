class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> pf(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pf[i][j] = mat[i][j];
                
                if(i > 0) pf[i][j] += pf[i-1][j];
                if(j > 0) pf[i][j] += pf[i][j-1];
                if(i > 0 && j > 0) pf[i][j] -= pf[i-1][j-1];
            }
        }
        
        int ans = 0;
        
        //sum=pf[r2][c2]−pf[r1−1][c2]−pf[r2][c1−1]+pf[r1−1][c1−1]
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<min(n-i,m-j); k++){
                    int sum = pf[i+k][j+k];
                    
                    if(i > 0) sum -= pf[i-1][j+k];
                    if(j > 0) sum -= pf[i+k][j-1];
                    if(i > 0 && j > 0) sum += pf[i-1][j-1];
                    
                    ans += sum==x ;
                }
            }
        }
        
        return ans;
    }
};